#pragma once
#include "ofMain.h"
#include "Ball.h"
#include <vector>
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

		std::vector<Ball>balls; //balls heeft meerdere Ball. dit is dus een lijst met ballen die ik later ga toepassen wanneer ik klik
		
		ofxPanel gui;
		ofParameter<int> radius;
		ofParameter<float>speedX;
		ofParameter<float>speedY;
		//ofParameter<ofColor>color;
};
