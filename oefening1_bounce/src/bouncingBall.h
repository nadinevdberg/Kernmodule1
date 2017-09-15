#pragma once
#include <ofMain.h>

class bouncingBall
{
public:
	bouncingBall();
	~bouncingBall();
	void setup();
	void draw();
	void update();

private:
	float x;
	float y;
	
	float speedX;
	float speedY;

	int radius;
	ofColor color;
};

