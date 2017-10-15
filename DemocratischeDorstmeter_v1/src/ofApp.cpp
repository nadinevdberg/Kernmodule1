#include "ofApp.h"
#define PIN_BUTTON1 12
#define PIN_BUTTON2 9
#include <glut.h>

//--------------------------------------------------------------
void ofApp::setup() {

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);		//Luister naar opstartsignaal van de Arduino
	arduino.connect("COM3"); //maak verbinding met de arduino die aan deze poort verbonden zit
	arduino.sendFirmwareVersionRequest();
	ofLog() << "Boolean button 1 status: " << b1Pressed << endl;
}

//--------------------------------------------------------------
void ofApp::update() {
	arduino.update(); //is er iets veranderd in de arduino?
}

//--------------------------------------------------------------
void ofApp::draw() {
	
}

void ofApp::setupArduino(const int & version)
{
	//verwijder listener
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	//print firmware details
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName() << arduino.getMajorFirmwareVersion() << arduino.getMinorFirmwareVersion() << endl;

	arduino.sendDigitalPinMode(11, ARD_OUTPUT);		//Digitaal output    dit was het lampje in voorbeeld code
	arduino.sendDigitalPinMode(12, ARD_INPUT);		//digitaal input
	arduino.sendAnalogPinReporting(0, ARD_ANALOG); //analoog uitlezen

	//functies die aangeroepen worden op het moment dat oF door heeft dat er een waarde veranderd is
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}

void ofApp::analogPinChanged(const int & pin)
{


	// 	ofLog() << "Analog pin" << pin << "value: " << arduino.getAnalog(pin) << endl;
}

void ofApp::digitalPinChanged(const int & pin)
{
	if (arduino.getDigital(12)) {

		if (b1Pressed) {
			b1Pressed = false;
			ofLog() << "Boolean button 1 status: " << b1Pressed << endl;
			glutTimerFunc(3000, timerCallBack, 1);
		}

		if (studentenMetDorst < studenten) {
			studentenMetDorst = studentenMetDorst + 1;
			ofLog() << "Op dit moment hebben " << studentenMetDorst << " studenten dorst" << endl;

		}
		if (studentenMetDorst == 10) {
			ofLog() << "Alle studenten hebben dorst! Tijd voor pauze?" << endl;
		}

	}

	/*	if (arduino.getDigital(9)) {

			if (studentenMetDorst < studenten / 2) {
				ofLog() << "Minder dan de helft van alle studenten heeft dorst. De pauze zal moeten wachten" << endl;
			}
			if (studentenMetDorst >= studenten / 2) {
				ofLog() << "De pauze is geactiveerd!" << endl;
				studentenMetDorst = 0;
			}
		}
		*/
}

void ofApp::timerCallBack(int status)
{

}

