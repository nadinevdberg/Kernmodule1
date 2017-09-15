#pragma once

#include "ofMain.h"
#include "bouncingBall.h"
#define NBALLS 50

class ofApp : public ofBaseApp{

	public:
		bouncingBall myBall[NBALLS];
		void setup();
		void update(); //rekenwerk voor bijvoorbeel posities of uitlezen van arduino
		void draw(); // kan alleen gebruikt worden voor teken operaties

		void keyPressed(int key);

};
