#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		int studentenMetDorst;
		int studenten = 10;
		ofSoundPlayer voicePlayer[6];
		bool playing[6];
};
