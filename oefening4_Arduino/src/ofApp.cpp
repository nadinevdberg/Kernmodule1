#include "ofApp.h"


void ofApp::setup(){
	//stap 1
	//functie van oF. zorgt dat je app luistert naar het opstartsignaal van Arduino
	ofAddListener(arduino.EInitialized, this,
		&ofApp::setupArduino);

	//stap 2
	//start arduino (maak nu verbinding met de arduino die aan deze poort verbonden zit)
	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();
}


void ofApp::update(){

}


void ofApp::draw(){

}


void ofApp::keyPressed(int key){

}


void ofApp::keyReleased(int key){

}

void ofApp::setupArduino(const int& version) {
	//stap 3
	//wordt aangeroepen op het moment dat oF en arduino communiceren
	//hier vragen we informatie uit de arduino
	ofLog() << "Arduino firmware found" << arduino.getFirmwareName()
		<< arduino.getMajorFirmwareVersion()
		<< arduino.getMinorFirmwareVersion() << endl;
	
	//stap 4
	//welke pin gebruiken we en waar gebruiken we hem voor
	arduino.sendDigitalPinMode(11, ARD_OUTPUT);			//digitaal output
	arduino.sendDigitalPinMode(12, ARD_INPUT);			//digitaal input
	arduino.sendAnalogPinReporting(0, ARD_ANALOG);		//uitlezen
	arduino.sendAnalogPinReporting(1, ARD_ANALOG);		// uitlezen

	//stap 5
	//als de waarde veranderd is, wat moet je er dan mee doen
	//functies die aangeroepen worden op het moment dat OF door heeft dat er een waarde veranderd is
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);

	//stap 6
	// arduino omgeving --> examples --> firmata --> standaard firmata
}

void ofApp::analogPinChanged(const int& pin) {

}

void ofApp::digitalPinChanged(const int& pin) {

}