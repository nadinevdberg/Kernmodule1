#pragma once
#include "ofMain.h"


class Ball
{
public:
	Ball();
	~Ball();
	void setup(int, float, float);
	void update();
	void draw();

	float x;
	float y;
	float speedX;
	float speedY;
	int radius;
	ofColor color;


};

