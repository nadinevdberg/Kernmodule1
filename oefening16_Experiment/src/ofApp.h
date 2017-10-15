#pragma once

#include "ofMain.h"

#define MESH_SIZE 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofBoxPrimitive box;
		float spinX = 0.005;
		float spinY = 0.005;

		ofVideoGrabber grabber;
		ofLight light;

		vector<float> origZ;
		ofImage image;

		ofPixels workspace;
		int randomRmutation;
		int randomGmutation;
		int randomBmutation;
		
};


/*
void keyPressed(int key);
void keyReleased(int key);
void mouseMoved(int x, int y );
void mouseDragged(int x, int y, int button);
void mousePressed(int x, int y, int button);
void mouseReleased(int x, int y, int button);
void mouseEntered(int x, int y);
void mouseExited(int x, int y);
void windowResized(int w, int h);
void dragEvent(ofDragInfo dragInfo);
void gotMessage(ofMessage msg);
*/