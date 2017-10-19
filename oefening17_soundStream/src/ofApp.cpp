#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(20);

	soundStream.printDeviceList();
	soundStream.setDeviceID(0);
	soundStream.setup(this, 2, 0, 44100, 512, 4); //aantal kanalen (L,R), input channels, Samplerate (hoe kleiner de stappen, hoe beter het geluid), laatste 2 zijn voor de buffertjes

}

void ofApp::update()
{
}

void ofApp::audioOut(float * output, int bufferSize, int nChannels)
{
	for (int i = 0; i < bufferSize * nChannels; i += 2) {
		float sample = sin(phase * 1.008f);

		output[i] = sample;
		sample = sin(phase);
		output[i + 1] = sample;
		step -= 0.0001;
		phase += step;
	}
}

