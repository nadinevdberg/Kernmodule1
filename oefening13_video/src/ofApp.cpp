#include "ofApp.h"


void ofApp::setup() {
	grabber.listDevices();//lijst met opties voor cam
	grabber.setDeviceID(0); // kies cam
	grabber.initGrabber(320, 240);	//grootte scherm
	grabber.setDesiredFrameRate(30);

	workspace.allocate(320, 240, ofImageType::OF_IMAGE_COLOR); //Wil weten of het zwart wit is, kleur is, etc

	randomRmutation = ofRandom(255);
	randomGmutation = ofRandom(255);
	randomBmutation = ofRandom(255);
}


void ofApp::update() {
	grabber.update();
	if (grabber.isFrameNew()) {   //is er een nieuw frame? doe dan.....
		ofPixels& pixels = grabber.getPixels(); //reference refereert naar origineel (&)
		for (int y = 0; y < pixels.getHeight(); y++) {
			for (int x = 0; x < pixels.getWidth(); x++) {
				ofColor c = pixels.getColor(x, y);
				
				//kleurwaarde inventeren van ieder pixel
				c.r = randomRmutation - c.r;
				c.g = randomGmutation - c.g;
				c.b = randomBmutation - c.b;

				//pixels uit webcam terugzetten in workspace
				workspace.setColor(x,y,c);

			}
		}
		image.setFromPixels(workspace); //image vullen met net aangemaakte pixels
	}
}



void ofApp::draw() {

	image.draw(0, 0, 320 *3, 240 * 3);  //maak even 3x zo groot

	if (drawGrabbedImage) {
		grabber.draw(0, 0); //positie X, Y
	}
}

void ofApp::keyPressed(int key)
{
	if (key == 'g') {
		drawGrabbedImage = !drawGrabbedImage;
	}

	if (key == ' ') {
		randomRmutation = ofRandom(255);
		randomGmutation = ofRandom(255);
		randomBmutation = ofRandom(255);
	}
}


