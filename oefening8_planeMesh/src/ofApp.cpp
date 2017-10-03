#include "ofApp.h"
#define WIDTH 480
#define HEIGHT 318
//--------------------------------------------------------------


void ofApp::setup() {
	image.load("karel.jpg");

	plane.set(WIDTH, HEIGHT);
	plane.setResolution(50, 50);

	//plaatje uitsmeren over mesh
	plane.mapTexCoordsFromTexture(image.getTexture());
}

//--------------------------------------------------------------
void ofApp::update() {
	plane.getMesh();
	ofMesh& mesh = plane.getMesh();
	for (int y = 0; y < 50; y++) {
		for (int x=0; x < 50; x++) {
			int index = x + 50*y;

			ofPoint vertex = mesh.getVertex(index);
			vertex.z = ofNoise(x*0.05, y*0.05, ofGetElapsedTimef()*0.5) * 100;

			mesh.setVertex(index, vertex);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(ofColor::black);
	cam.setVFlip(true);
	cam.begin();
	//bind huidig plaatje aan wireframe
	image.bind();
	//plane.drawWireframe();
	plane.draw();
	image.unbind();
	cam.end();
}

