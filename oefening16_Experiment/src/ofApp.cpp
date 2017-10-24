#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	grabber.setDeviceID(0);
	grabber.initGrabber(320, 240);
	grabber.setDesiredFrameRate(30);

	workspace.allocate(320, 240, ofImageType::OF_IMAGE_COLOR);

	box.set(200, 400, 200);
	box.setResolution(MESH_SIZE);
	box.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	box.mapTexCoordsFromTexture(grabber.getTexture());

	ofMesh& mesh = box.getMesh();

	for (unsigned int index = 0; index < mesh.getNumVertices(); index++) {
		ofPoint vertex = mesh.getVertex(index);
		origZ.push_back(vertex.z);
	}

	randomRmutation = ofRandom(255);
	randomGmutation = ofRandom(255);
	randomBmutation = ofRandom(255);

	//light.setDirectional();
	//light.enable();
}

//--------------------------------------------------------------
void ofApp::update() {

	grabber.update();
	if (grabber.isFrameNew()) {
		ofPixels& pixels = grabber.getPixels();

		ofMesh& mesh = box.getMesh();

		for (int y = 0; y < MESH_SIZE * 2; y++) {
			for (int x = 0; x < MESH_SIZE; x++) {

				ofColor c = pixels.getColor(x, y);
				c.r = randomRmutation;
				c.g = randomGmutation;
				c.b = randomBmutation;
				workspace.setColor(x, y, c);

				int index = x + MESH_SIZE * y;
				ofPoint vertex = mesh.getVertex(index);

				vertex.z = origZ[index] +
					ofNoise(x*0.5, y*0.5, ofGetElapsedTimef()*0.5) * 50 - 25;
				mesh.setVertex(index, vertex);



				// dit deel werkt niet:
					float colour = ofNoise(x*0.02, y*0.02, ofGetElapsedTimef()*0.5);

					ofColor color;

					color.setHsb(colour * 255, 255, 128);

					mesh.setColor(index, color);
					

			}
		}
		image.setFromPixels(workspace);
		
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(ofColor::black);
	image.draw(0, 0, 320 * 3, 240 * 3);

	if (drawGrabbedImage) {
		grabber.draw(0, 0);
	}

	box.rotate(spinX, 1, 0, 0);
	box.rotate(spinY, 0, 0, 1);
	ofSetColor(ofColor::white);

	ofEnableDepthTest();
	
	grabber.getTexture().bind();
	box.draw();
	grabber.getTexture().unbind();
	ofDisableDepthTest();
}

void ofApp::keyPressed(int key)
{
	if (key == ' ') {
		drawGrabbedImage = !drawGrabbedImage;
	}
}


