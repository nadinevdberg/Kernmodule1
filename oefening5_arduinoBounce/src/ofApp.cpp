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
		myBall.setup((int)round(ballRadius), 0.5, 1);
		balls.push_back(myBall);


		ofLog() << "mijn radius  = "<< myBall.radius << endl;
		ofLog() << "ballRadius = " << round (ballRadius) << endl;
	}
	else {
		ofLog() << "ik doe niks!" << endl;
	}


}

void ofApp::analogPinChanged(const int& pinNum) {

	// gebruik de waarde van analog pin1 (potmeter)
	int potRadius = (arduino.getAnalog(1));
	

	float maxRadius = 100;
	float minRadius = 5;

	//maximale radius delen door de maximale waarde van de potmeter, vermenigvuldigen met potradius
	ballRadius = (maxRadius / 1023)* potRadius;
	if (ballRadius <= minRadius) {
		ballRadius = minRadius;
	}


}

/*
Ball myBall;
myBall.setup(10, 2, 3);
balls.push_back(myBall);

ofLogNotice() << "Digital Pin " << pinNum << "value: " << arduino.getDigital(pinNum) << endl;

*/