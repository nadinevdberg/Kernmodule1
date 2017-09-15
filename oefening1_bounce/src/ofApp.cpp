#include "ofApp.h"
#include "bouncingBall.h"


//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i<NBALLS; i++) {
		myBall[i].setup();
	}
	ofBackground(10,10,10);

	

}

//--------------------------------------------------------------

void ofApp::update() {
	for (int i = 0; i<NBALLS; i++) {
		myBall[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i<NBALLS; i++) {
		myBall[i].draw();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

