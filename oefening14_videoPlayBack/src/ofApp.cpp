#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.load("filmpje.mp4");
	video.play();
	video.setLoopState(OF_LOOP_NORMAL);
	rotate = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	rotate++;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::white);
	video.draw(0, 0);

	ofSetColor(ofColor::blueSteel);
	ofScale(0.7, 0.7, 0.7);
	ofTranslate(400, 200);
	ofRotateY(rotate); //VOLGORDE IS BELANGRIJK. ZET DIT VOOR DE DRAW!
	ofRotateX(rotate);
	video.draw(0, 0);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

