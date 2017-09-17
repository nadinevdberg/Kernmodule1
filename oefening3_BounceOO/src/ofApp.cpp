#include "ofApp.h"
#include "Ball.h"


void ofApp::setup(){
	for (int i = 0; i < MAXBALLS; i++) { //ik begrijp niet goed wat een array precies doet. Dit is overgenomen van het voorbeeld van de docent
		ball[i].setup();
	}
}
void ofApp::update(){
	for (int i = 0; i < MAXBALLS; i++) {
		ball[i].update();
	}
		
}

void ofApp::draw(){
	for (int i = 0; i < MAXBALLS; i++) {
		ball[i].update();
	}
}

void ofApp::keyPressed(int key){
	if (key == ' ')
	{
		ofLog() << "spatiebalk ingedrukt" << endl;
	}
	else {
		ofLog() << "er gebeurt niks" << endl;
	}
	
}



void ofApp::mousePressed(int x, int y, int button){
	
}


