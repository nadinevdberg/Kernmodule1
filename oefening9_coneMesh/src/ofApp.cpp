#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	primitive = ofConePrimitive(coneRadius, coneHeight,
		coneRadiusSegments, coneHeightSegments);
	primitive.setMode(OF_PRIMITIVE_TRIANGLES);
}

//--------------------------------------------------------------
void ofApp::update() {
	//triangle faces verplaatsen
	vector<ofMeshFace> triangles = primitive.getMesh().getUniqueFaces();

	float displacement = sin(ofGetElapsedTimef() * 4) * 10;
	for (int i = 0; i < triangles.size(); i++) {

		//ofvec3F = vector met 3 floats
		ofVec3f faceNormal = triangles[i].getFaceNormal();

		for (int j = 0; j < 3; j++) {
			triangles[i].setVertex(j, triangles[i].getVertex(j) + faceNormal*displacement);
		}

	}
	primitive.getMesh().setFromTriangles(triangles);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSetColor(20, 35, 255);
	primitive.draw();

}


