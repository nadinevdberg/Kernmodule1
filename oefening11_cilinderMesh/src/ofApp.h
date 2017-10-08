#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofCylinderPrimitive cylinder;
		float cylinderRadius = 200;
		float cylinderHeight = 400;
		float spinX = 0.025;
		float spinY = 0.025;
	
		ofImage image;

};
