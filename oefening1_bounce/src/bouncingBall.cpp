#include "bouncingBall.h"



bouncingBall::bouncingBall()
{
}


bouncingBall::~bouncingBall()
{
}

void bouncingBall::setup()
{
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	speedX = ofRandom(-2, 2);
	speedY = ofRandom(-2, 2);
	radius = ofRandom(2, 80);
}

void bouncingBall::update()
{
	if (x < 0) {
		x = 0;
		speedX = -speedX;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
	}

	if (y < 0) {
		y = 0;
		speedY = -speedY;
	}
	else if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY = -speedY;
	}

	x += speedX;
	y += speedY;
}

void bouncingBall::draw()
{
	ofSetColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
	ofDrawCircle(x, y, radius);
}

