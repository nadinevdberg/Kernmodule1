#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	image.load("pattern.jpg");							//afbeelding inladen

	cylinder.set(cylinderRadius, cylinderHeight);		//cylinder opzetten
	cylinder.setResolution(100, 100);					//resolutie cylinder: hoe lager, hoe hoekiger de vorm

	cylinder.mapTexCoordsFromTexture(image.getTexture()); //plaatje uitsmeren over de mesh
}

//--------------------------------------------------------------
void ofApp::update(){
	cylinder.getMesh();								//mesh ophalen
	ofMesh& mesh = cylinder.getMesh();				

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			int index = x + 100 * y;
			
			ofPoint vertex = mesh.getVertex(index);
			vertex.z = ofNoise(x*0.25, y*0.25, ofGetElapsedTimef()*0.5) * 100;
			mesh.setVertex(index, vertex);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(ofColor::black);			//achtergrond kleur

	image.bind();				// bind huidig plaatje aan wireframe

	ofSetColor(ofColor::white);
	cylinder.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	cylinder.rotate(spinX, 1, 0, 1);
	cylinder.rotate(spinY, 0, 1, 0);

	cylinder.drawWireframe();
	//cylinder.draw();

	image.unbind(); 

}
