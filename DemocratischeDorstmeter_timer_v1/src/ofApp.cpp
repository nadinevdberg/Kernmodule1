#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofLog() << "start " << endl;

}

//--------------------------------------------------------------
void ofApp::update(){
	glutTimerFunc(1, callbackFunction, 1);
}

//--------------------------------------------------------------
void ofApp::draw(){

}



void callbackFunction(int status)
{

	ofLog() << "HOI " << endl;
		if (status == 1) {  //repeat  
			callbackFunction(1);
		}
}
