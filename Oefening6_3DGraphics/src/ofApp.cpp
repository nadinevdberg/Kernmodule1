#include "ofApp.h"

 
void ofApp::setup(){
	ofBackground(ofColor::black);
}

 
void ofApp::update(){
	rotateX = rotateX + 0.5;
	rotateY = rotateY + -0.1;
	rotateZ = rotateZ + 0.3;
}



void ofApp::draw(){

	//verplaats het hele assenkruis naar het midden van het scherm
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	//eerst de positie, dan tekenen
	
	//assen draaien
	if (rotate) {
		ofRotateX(rotateX);
		ofRotateY(rotateY);
		ofRotateZ(rotateZ);
	}

	if (drawGrid) {
		ofDrawGrid(30);
	}
	ofNoFill();
	ofSetColor(ofColor::orangeRed);
	ofDrawSphere(20, 20, 20, 200);
}

void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGrid = !drawGrid;
	}

	if (key == ' '){
		rotate = !rotate;
	}
}


