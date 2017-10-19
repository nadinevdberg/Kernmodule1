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
	int studentenMetDorst =0;
	int studenten =10;

	bool b1Pressed = true;
	ofSoundPlayer audio;

	ofTrueTypeFont myFont;
	string smd;
	string percentage;
	string begroeting;

	float procent;
};
	