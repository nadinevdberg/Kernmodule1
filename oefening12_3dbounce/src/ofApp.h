#pragma once

#include "ofMain.h"
#include "Ball.h"
#define NBALLS 50


class ofApp : public ofBaseApp{

	public:

		Ball myBall[NBALLS];
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

private:
	bool rotate = false;
	float rotateX;
	float rotateY;
	float rotateZ;
	int depth;

	

};
