#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(ofColor::black);
	gui.setup();
	gui.add(drawGrid.set("Grid",false));
	gui.add(useLight.set("Light", true));

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0,0,0));
	light.setDiffuseColor(ofColor::white);
	light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();

	ofEnableDepthTest();

	cam.begin();
	ofSetColor(ofColor::orangeRed);
	ofNoFill();
	ofDrawSphere(0, 0, 0, 50);

	ofSetColor(ofColor::lightSkyBlue);
	ofNoFill();
	ofDrawSphere(100, 0, 0, 20);

	ofSetColor(ofColor::peachPuff);
	ofNoFill();
	ofDrawSphere(-100, 0, 0, 20);

	ofSetColor(ofColor::lightSeaGreen);
	ofNoFill();
	ofDrawSphere(0, 100, 0, 20);

	if (drawGrid) ofDrawGrid(80);

	if (useLight) {
		ofEnableLighting();
	}
	else {
		ofDisableLighting();
	}
	cam.end();
	ofDisableDepthTest();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	

}

