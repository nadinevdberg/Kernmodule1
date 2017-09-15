#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup("instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 0, 200)); //start waarde, minimum waarde en maximum waarde
	gui.add(speedX.set("SpeedX", 50, 0, 200));
	gui.add(speedY.set("SpeedY", 50, 0, 200));
	gui.add(color.set("Color", ofColor::white));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		ofLog() << "WAT DOE JE?!" << endl;
	}
	else {
		ofLog() << "Oh noh! Rustaaaaag" << endl;//bestaat altijd. magisch. kun je tekst naartoe sturen
	}
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
