#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);		//Luister naar opstartsignaal van de Arduino
	arduino.connect("COM3"); //maak verbinding met de arduino die aan deze poort verbonden zit
	arduino.sendFirmwareVersionRequest();
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
	ofLog() << "Analog pin" << pin << "value: " << arduino.getAnalog(pin) << endl;
}

void ofApp::digitalPinChanged(const int & pin)
{
	ofLog() << "Digital pin" << pin << "value: " << arduino.getDigital(pin) << endl;
}

