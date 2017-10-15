#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

void ofApp::keyPressed(int key)
{
	if (key == ' ')
	{
		if (studentenMetDorst < studenten) {
			studentenMetDorst = studentenMetDorst + 1;
			ofLog() << "Op dit moment hebben " << studentenMetDorst << " studenten dorst" << endl;
		}
		if (studentenMetDorst == 10) {
			ofLog() << "Alle studenten hebben dorst! Tijd voor pauze?" << endl;
		}
	
	}

	if (key == 'p')
	{
		if (studentenMetDorst < studenten/2) {
			ofLog() << "Minder dan de helft van alle studenten heeft dorst. De pauze zal moeten wachten" << endl;
		}
		if (studentenMetDorst >= studenten/2) {
			ofLog() << "De pauze is geactiveerd!" << endl;
			studentenMetDorst = 0;
		}
	}
}


