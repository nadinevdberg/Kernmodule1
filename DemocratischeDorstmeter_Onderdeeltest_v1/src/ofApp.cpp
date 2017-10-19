#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	for (int i = 0; i < 6; i++) {
		voicePlayer[i].load(ofToDataPath("vox" + ofToString(i + 1) + ".wav"));
		voicePlayer[i].setLoop(true);
		voicePlayer[i].play();
		//voicePlayer[i].setSpeed(3.0f);
		voicePlayer[i].setPaused(true);
	}

	ofSoundSetVolume(0.5);


}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();  //niet altijd nodig
	float time = ofGetElapsedTimef();
	float x = time* 0.1f + 30;
/*	for (int i = 0; i < 6; i++) {
		float y = i*0.02f;
		float volume = ofNoise(x, y);
		voicePlayer[i].setVolume(volume);
		voicePlayer[i].setSpeed(volume*3);
	}*/
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < 6; i++) {
		ofSetColor(i * 20 + 128, i * 80, i * 10 + 60);
		ofDrawRectangle(100, i * 30 + 200, voicePlayer[i].getVolume() * 300, 5);
	}
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
		if (studentenMetDorst < studenten / 2) {
			ofLog() << "Minder dan de helft van alle studenten heeft dorst. De pauze zal moeten wachten" << endl;
		}
		if (studentenMetDorst >= studenten / 2) {
			ofLog() << "De pauze is geactiveerd!" << endl;
			studentenMetDorst = 0;
			//playing[1] = !playing[1];
		}
	}

	if (key == '1') {
		playing[0] = !playing[0];
		voicePlayer[0].setPaused(playing[0]);
	}

	if (key == '2') {
		playing[1] = !playing[1];
		voicePlayer[1].setPaused(playing[1]);
	}

	if (key == '3') {
		playing[2] = !playing[2];
		voicePlayer[2].setPaused(playing[2]);
	}

	if (key == '4') {
		playing[3] = !playing[3];
		voicePlayer[3].setPaused(playing[3]);
	}

	if (key == '5') {
		playing[4] = !playing[4];
		voicePlayer[4].setPaused(playing[4]);
	}

	if (key == '6') {
		playing[5] = !playing[5];
		voicePlayer[5].setPaused(playing[5]);
	}


}
