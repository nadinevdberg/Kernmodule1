#pragma once
#include "ofxGui.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	ofxPanel gui;

	//hiermee kan ik hem in de gui aanspreken
	ofParameter<bool>drawGrid;
	ofParameter<bool>useLight;


	ofLight light;

	//translate origing naar het midden en flipt assenstelsel
	ofEasyCam cam;


private:
	bool rotate = true;
	float rotateX;
	float rotateY;
	float rotateZ;

};
