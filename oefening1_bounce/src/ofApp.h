#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update(); //rekenwerk voor bijvoorbeel posities of uitlezen van arduino
		void draw(); // kan alleen gebruikt worden voor teken operaties

		void keyPressed(int key);

private:
	float x;
	float y;
	float a;
	float b;
	float c;
	float d;

	float speedX;
	float speedY;
	float speedA;
	float speedB;
	float speedC;
	float speedD;


	int radiusA; 
	int radiusB;
	int radiusC;
	ofColor color;

};
