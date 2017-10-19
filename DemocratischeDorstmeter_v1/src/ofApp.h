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
	int studenten = 25;

	bool b1Pressed = true;
	
};
