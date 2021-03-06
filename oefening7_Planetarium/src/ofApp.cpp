#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);

	gui.setup();
	gui.add(drawGrid.set("Grid", false));
	gui.add(useLight.set("Light", true));

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor::white);
	light.enable();
}

//--------------------------------------------------------------
void ofApp::update() {


	//ofRotateZ(1);
	//ofRotateY(1);

	rotateX = rotateX + 0.5;
	rotateY = rotateY + 0.2;
	rotateZ = rotateZ + 0.2;
}

//--------------------------------------------------------------
void ofApp::draw() {

	gui.draw();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);


	ofEnableDepthTest();

	if (rotate) {
		ofRotateY(rotateY);

	}
	//cam.begin();
	// Planeet 1


	ofSetColor(ofColor::goldenRod);
	ofNoFill();
	ofDrawSphere(0, 0, 0, 50);


	// Planeet 2
	ofSetColor(ofColor::darkGreen);
	ofNoFill();
	ofDrawSphere(125, 0, 0, 20);

	// Planeet 4
	ofSetColor(ofColor::lightSkyBlue);
	ofNoFill();
	ofDrawSphere(200, 0, 0, 20);

	if (drawGrid) ofDrawGrid(80);



	if (useLight) {
		ofEnableLighting();
	}
	else {
		ofDisableLighting();
	}
	//cam.end();
	ofDisableDepthTest();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'l') {
		useLight = !useLight;
	}

	if (key == 'g') {
		drawGrid = !drawGrid;
	}

	if (key == 'r') {
		rotate = !rotate;
	}
}

