#pragma once

#include "ofMain.h"
#include "Ball.h"
#define MAXBALLS 50

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

		Ball ball[MAXBALLS];
		
};
