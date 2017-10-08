#pragma once
#include "ofMain.h"

class Ball
{
public:
	Ball();
	~Ball();

	void setup();
	void update();
	void draw();

	float x;
	float y;
	float z;
	float speedX;
	float speedY;
	float speedZ;
	int radius;

	ofColor color;
};

