#include "ofApp.h"
#include "Ball.h"

//--------------------------------------------------------------
void ofApp::setup(){

	

	ofBackground(ofColor::black);

	for (int i = 0; i < NBALLS; i++) {
		myBall[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	// experiment met rotatie
	rotateX = rotateX + 0.05;
	rotateY = rotateY + 0.05;
	rotateZ = rotateZ + 0.05;
	
	for (int i = 0; i < NBALLS; i++) {
		myBall[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {


	if (rotate)
	{
		ofRotateX(rotateX);
		ofRotateY(rotateY);
		ofRotateZ(rotateZ);
	}




	for (int i = 0; i < NBALLS; i++) {
		myBall[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	if (key == 'r') {
		rotate = !rotate;
	}
}


