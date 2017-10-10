#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofVideoGrabber grabber; //webcam 
		ofEasyCam cam;
		ofLight light;
		ofSpherePrimitive sphere1; //minder poly's dan een gewone sphere
		
		ofBoxPrimitive box1;
		ofConePrimitive cone1;
		ofPlanePrimitive plane1;
};
