#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		
private:
	ofArduino arduino; //arduino communicatie class

	void setupArduino(const int& version); //wordt aangeroepen door arduino class als je arduino klaar is met opstarten

	void analogPinChanged(const int & pin);

	void digitalPinChanged(const int & pin);

		
};
