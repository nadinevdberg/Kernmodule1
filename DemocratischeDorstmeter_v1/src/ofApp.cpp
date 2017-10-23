#include "ofApp.h"
#define PIN_BUTTON1 12
#define PIN_BUTTON2 9




void ofApp::setup() {

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);		//Luister naar opstartsignaal van de Arduino
	arduino.connect("COM3"); //maak verbinding met de arduino die aan deze poort verbonden zit
	arduino.sendFirmwareVersionRequest();
	ofLog() << "Boolean button 1 SETUP status: " << b1Pressed << endl;

	audio.load(ofToDataPath("Holy.wav"));
	audio.play();
	audio.setPaused(true);
	ofSoundSetVolume(0.2);

	ofTrueTypeFont::setGlobalDpi(72);
	myFont50.load("Oswald-Regular.ttf", 50);
	myFont30.load("Oswald-Regular.ttf", 30);

	begroeting = "Hallo Joyce!";

}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	arduino.update(); //is er iets veranderd in de arduino?

	procent = (studentenMetDorst / studenten) * 100.0f;
	percentage = ofToString(procent);

	if (studentenMetDorst > studenten / 2) {
		dorst = true;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(ofColor::black);
	ofSetColor(255, 128, 0);
	myFont50.drawString(begroeting, 500, 300);

	if (!pauze) {
		if (studentenMetDorst < studenten) {
			myFont30.drawString("Op dit moment heeft " + percentage + "% van alle studenten dorst", 500, 350);
		}
		if (studentenMetDorst == studenten) {
			myFont30.drawString("Alle studenten hebben dorst! Activeer de pauze a.u.b!", 500,350);
		}
		if (dorst){
			myFont30.drawString("Meer dan de helft van de studenten heeft dorst. De pauze kan geactiveerd worden", 500, 400);
		}
	}
	if (pauze) {
		myFont30.drawString("Pauze is geactiveerd. Haal snel je drankje uit de koelbox!", 500, 350);

	}

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
	//	ofLog() << "Digital Pin" << pin << " changed to " << value << endl;


	if (pin == PIN_BUTTON1 && value == 1) {
		//ofLog() << "Boolean Dorst button status: " << b1Pressed << endl;
		if (b1Pressed) {
			b1Pressed = false;
		}

		if (studentenMetDorst < studenten) {
			studentenMetDorst = studentenMetDorst + 1;
			ofLog() << "Op dit moment hebben " << studentenMetDorst << " studenten dorst" << endl;

		}


		if (studentenMetDorst == studenten) {
			ofLog() << "Alle studenten hebben dorst. Activeer pauze a.u.b!" << endl;
		}

	}

	if (pin == PIN_BUTTON2 && value == 1) {

		if (studentenMetDorst <= studenten / 2) {
			ofLog() << "Minder dan de helft van alle studenten heeft dorst. De pauze zal moeten wachten" << endl;
			
		}
		if (studentenMetDorst > studenten / 2) {
			ofLog() << "De pauze is geactiveerd!" << endl;
			studentenMetDorst = 0;
			pauze = true;
			audio.setPaused(false);
		}

	}



}

