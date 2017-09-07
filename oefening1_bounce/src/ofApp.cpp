#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(10,10,10);

	// alle variabelen voor de start posities
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	a = ofRandom(0, ofGetWidth());
	b = ofRandom(0, ofGetHeight());
	c = ofRandom(0, ofGetWidth());
	d = ofRandom(0, ofGetHeight());

	// alle variabelen voor de snelheid van de vormen
	speedX = ofRandom(-2, 2);
	speedY = ofRandom(-2, 2);
	speedA = ofRandom(-1, 1);
	speedB = ofRandom(-1, 1);
	speedC = ofRandom(1, 2);
	speedD = ofRandom(1, 2);

	// alle variabelen voor de grootte van de ballen
	radiusA = ofRandom(2,80);
	radiusB = ofRandom(2, 80);
	radiusC = ofRandom(2, 80);

}

//--------------------------------------------------------------

void ofApp::update() {
// Zorgt dat de positie van de ballen veranderd
	if (x < 0) {
		x = 0;
		speedX = -speedX;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
	}

	if (a < 0) {
		a = 0;
		speedA = -speedA;
	}
	else if (a > ofGetWidth()) {
		a = ofGetWidth();
		speedA = -speedA;
	}

	if (c < 0) {
		c = 0;
		speedC = -speedC;
	}
	else if (c > ofGetWidth()) {
		c = ofGetWidth();
		speedC = -speedC;
	}


	if (y < 0) {
		y = 0;
		speedY = -speedY;
	}
	else if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY = -speedY;
	}

	if (b < 0) {
		b = 0;
		speedB = -speedB;
	}
	else if (b > ofGetHeight()) {
		b = ofGetHeight();
		speedB = -speedB;
	}
	
	if (d < 0) {
		d = 0;
		speedD = -speedD;
	}
	else if (d > ofGetHeight()) {
		d = ofGetHeight();
		speedD = -speedD;
	}
	
	// zorgt ervoor dat de variabele aan waarde veranderd
	x += speedX;
	y += speedY;
	a += speedA;
	b += speedB;
	c += speedC;
	d += speedD;
}

//--------------------------------------------------------------
void ofApp::draw(){
	// als ik de kleur in de setup zet ipv draw, zal deze niet constant veranderen
	ofSetColor(ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0, 255)));
	ofDrawCircle(x, y, radiusA);
	ofDrawCircle(a, b, radiusB);
	ofDrawCircle(c, d, radiusC);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

