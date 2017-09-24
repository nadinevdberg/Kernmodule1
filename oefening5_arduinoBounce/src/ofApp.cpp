#include "ofApp.h"
#include "Ball.h"
#define PIN_BUTTON 12
#define PIN_POTMETER 1



void ofApp::setup(){
	// zorgt ervoor dat app naar opstartsignaal van arduino luistert
	ofAddListener(arduino.EInitialized, this,
		&ofApp::setupArduino);

	// Maak nu verbinding met de arduino die aan deze poort verbonden zit
	arduino.connect("COM3");

	// bugfix ofArduino/firmata bug
	arduino.sendFirmwareVersionRequest(); 
}


void ofApp::update(){
	// Is er iets veranderd in de arduino?
	arduino.update();


	// Update list voor de ball
	for (int i = 0;i < balls.size(); i++) 
	{
		balls[i].update();
	}
	
}


void ofApp::draw(){

	// Teken de ballen
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].draw();
	}

}

void ofApp::setupArduino(const int& version) {
	// Wordt aangeroepen zodra oF en Arduino communiceren. 

	// Listener is niet meer nodig, dus wordt verwijderd
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	// print versie en naam van firmware
	ofLog()<<"Arduino Firmware Found: " << arduino.getFirmwareName()
		<<" v" << arduino.getMajorFirmwareVersion()
		<< "." <<arduino.getMinorFirmwareVersion()<<endl;

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);

	// listener voor pin events
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
	// waarde met arduino.getDigital(pinNum));

	if (arduino.getDigital(12)) {
		Ball myBall;
		myBall.setup(10, 0.5, 1);
		balls.push_back(myBall);

		ofLog() << "Ik doe iets!" << endl;
	}
	else {
		ofLog() << "ik doe niks!" << endl;
	}


}

void ofApp::analogPinChanged(const int& pinNum) {
	
	// als de waarde van de potmeter omhoog gaat, moet de radius ook omhoog
	// als de waarde van de potmeter omlaag gaat, moet de radius ook omlaag 
	// als de nieuwe waarde hoger is dan de vorige waarde: groei
	// als de nieuwe waarde lager is dan de vorige waarde: krimp

	int potRadius = (arduino.getAnalog(1));
	ofLogNotice() << "potRadius = " << potRadius << endl;
	int maxRadius = 100;
	int minRadius = 5;
	//ballRadius = 


	if (arduino.getAnalog(1)) {

	}
	
	// waarde met arduino.getAnalog(pinNum));

	ofLogNotice() << "Analog Pin " << pinNum << "value: " << arduino.getAnalog(pinNum) << endl;

}

/*
Ball myBall;
myBall.setup(10, 2, 3);
balls.push_back(myBall);

ofLogNotice() << "Digital Pin " << pinNum << "value: " << arduino.getDigital(pinNum) << endl;

*/