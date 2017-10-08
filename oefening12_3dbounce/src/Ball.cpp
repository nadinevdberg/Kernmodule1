#include "Ball.h"



Ball::Ball()
{
}


Ball::~Ball()
{
}



void Ball::setup()
{
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	z = ofRandom(0, 50);

	speedX = 0.4;
	speedY = 0.2;
	speedZ = 0.3;
	radius = ofRandom(2,20);
	

	color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::update()
{
	if (x < 0) {
		x = 0;
		speedX = -speedX;
	}
	if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
	}

	if (y < 0) {
		y = 0;
		speedY = -speedY;
	}

	if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY = -speedY;
	}

	if (z < 0) {
		z = 0;
		speedZ = -speedZ;
	}
	if (z > 50) {
		z = 50;
		speedZ = -speedZ;
	}

	x += speedX;
	y += speedY;
	z += speedZ;
}

void Ball::draw()
{
	ofSetColor(color);
	ofDrawSphere(x, y, z, radius);
}
