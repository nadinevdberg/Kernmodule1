#include "ofApp.h"
#define PIN_BUTTON1 12
#define PIN_BUTTON2 9
#include <glut.h>



void ofApp::setup() {

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);		//Luister naar opstartsignaal van de Arduino
	arduino.connect("COM3"); //maak verbinding met de arduino die aan deze poort verbonden zit
	arduino.sendFirmwareVersionRequest();
	ofLog() << "Boolean button 1 SETUP status: " << b1Pressed << endl;
}

//--------------------------------------------------------------
void ofApp::update() {
	arduino.update(); //is er iets veranderd in de arduino?
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(ofColor::black);
}



void ofApp::setupArduino(const int & version)
{


	//print firmware details
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName() << arduino.getMajorFirmwareVersion() << arduino.getMinorFirmwareVersion() << endl;
	
	//verwijder listener
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON1, ARD_INPUT);		//Digitaal input
	arduino.sendDigitalPinMode(PIN_BUTTON2, ARD_INPUT);		//digitaal input


	//functies die aangeroepen worden op het moment dat oF door heeft dat er een waarde veranderd is
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}



void ofApp::digitalPinChanged(const int& pin)
 	{
	int value = arduino.getDigital(pin);
	ofLog() << "Digital Pin" << pin << " changed to " << value << endl;

	
	if (pin == PIN_BUTTON1 && value == 1) {
		ofLog() << "Boolean Dorst button status: " << b1Pressed << endl;
		if (b1Pressed) {
			glutTimerFunc(3000, timerCallBack, 1);
			b1Pressed = false;
		}

		if (studentenMetDorst < studenten) {
			studentenMetDorst = studentenMetDorst + 1;
			ofLog() << "Op dit moment hebben " << studentenMetDorst << " studenten dorst" << endl;
		}

		if (studentenMetDorst == 10) {
			ofLog() << "Alle studenten hebben dorst. Tijd voor pauze!" << endl;
		}

	}

	if (pin == PIN_BUTTON2 && value == 1) {

		if (studentenMetDorst < studenten / 2) {
			ofLog() << "Minder dan de helft van alle studenten heeft dorst. De pauze zal moeten wachten" << endl;
		}
		if (studentenMetDorst >= studenten / 2) {
			ofLog() << "De pauze is geactiveerd!" << endl;
			studentenMetDorst = 0;
		}
	}



}


void timerCallBack(int status)
{
	ofLog() << "TIMERCALLBACK WORDT AANGEROEPEN! " << endl;
	ofLog() << "huidige callback status: " << status << endl;
}
