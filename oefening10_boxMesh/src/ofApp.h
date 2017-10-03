#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofBoxPrimitive box;
		float boxSize = 500;
		float spinX = 0.2;
		float spinY = 1.0;
};
