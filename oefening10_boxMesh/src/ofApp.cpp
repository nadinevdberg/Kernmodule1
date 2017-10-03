#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	box.set(boxSize);
}

//--------------------------------------------------------------
void ofApp::update(){
	vector<ofMeshFace>triangles = box.getMesh().getUniqueFaces();

	float discplacement = sin(ofGetElapsedTimef() * 2) * 10;
	for (int i = 0; i < triangles.size(); i++) {
		ofVec3f faceNormal = triangles[i].getFaceNormal();
		
	
	


		for (int j = 0; j < 3; j++) {
			triangles[i].setVertex(j, triangles[i].getVertex(j) + faceNormal*discplacement);

			
		}
	}
	box.getMesh().setFromTriangles(triangles);
}


//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);
	box.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
	box.rotate(spinX, 1.0, 0.0, 0.0);
	box.rotate(spinY, 0, 1.0, 0.0);
	ofSetColor(ofColor::orangeRed);

	box.draw();

}

