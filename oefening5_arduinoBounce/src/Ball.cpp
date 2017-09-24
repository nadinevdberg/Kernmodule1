#include "Ball.h"



Ball::Ball()
{
}
Ball::~Ball()
{
}

void Ball::setup(int radiusSetting, float speedXSetting, float speedYSetting)
{
	x = ofRandom(0, ofGetWidth()); //willekeurige startpositie
	y -= ofRandom(0, ofGetHeight()); 

	speedX = speedXSetting;
	speedY = speedYSetting;
	radius = radiusSetting;

	color.set(ofRandom(255), ofRandom(255), ofRandom(255)); // willekeurige RGB waardes == willekeurige kleur
}

void Ball::update()
{

	//als de bal de rand raakt, moet hij omkeren
	if (x < 0) {
		x = 0;
		speedX = -speedX;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
	}

	if (y < 0)
	{
		y = 0;
		speedY = -speedY;
	}
	else if (y > ofGetHeight())
	{
		y = ofGetHeight();
		speedY = -speedY;
	}
	
	//hiermee wordt de snelheid van de bal ook echt aangepast - dus omgekeerd
	x += speedX;
	y += speedY;
}

void Ball::draw()
{
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}