#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();

		void audioOut(float* input, int bufferSize, int nChannels); //point naar buffer input, buffersize mocht je die vergeten, nchannel is hoeveel data je compute rnodig heeft

		float phase;
		float step = 0.001;
		ofSoundStream soundStream;

		
};
	