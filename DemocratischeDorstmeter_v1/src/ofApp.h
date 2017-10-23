#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
private:
	ofArduino arduino;
	void setupArduino(const int& version);
	void digitalPinChanged(const int & pin);
	float studentenMetDorst =0;
	int studenten =25;

	bool b1Pressed = true;
	ofSoundPlayer audio;

	ofTrueTypeFont myFont50;
	ofTrueTypeFont myFont30;
	string percentage;
	string begroeting;

	bool pauze = false;
	bool dorst = false;
	float procent;
};
	