#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		//void timerCallBack(int status);
private:
	ofArduino arduino;
	void setupArduino(const int& version);
	void analogPinChanged(const int & pin);
	void digitalPinChanged(const int & pin);
	int studentenMetDorst;
	int studenten = 10;

	bool b1Pressed = true;
	
};
