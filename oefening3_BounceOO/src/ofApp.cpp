#include "ofApp.h"
#include "Ball.h"



void ofApp::setup(){
	gui.setup("instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 0, 200)); //start waarde, minimum waarde en maximum waarde
	gui.add(speedX.set("SpeedX", 1, 0, 2));
	gui.add(speedY.set("SpeedY", 1, 0, 2));
	//gui.add(color.set("Color", ofColor::white));
}
void ofApp::update(){
	for (int i = 0; i < balls.size(); i++) { //dit update de list
		balls[i].update();
	}
		
}

void ofApp::draw(){ //class ofApp heeft een methode genaamd draw
	for (int i = 0; i < balls.size(); i++) { //dit zorg voor het tekenen van de ballen 
		balls[i].draw();
	}
	gui.draw();				//tekent de GUI
}

void ofApp::keyPressed(int key){
	if (key == ' ')
	{
		//dit zorgt ervoor dat, als er minstens 1 bal is, de laatst toegevoegde bal verwijderd wordt
		if (balls.size() > 0) {
			balls.erase(balls.end() - 1); //-1 is belangrijk, anders werkt het niet. hier kan ook balls.pop_back(); gebruikt worden
		}
		ofLog() << "spatiebalk ingedrukt" << endl;
	}
	else {
		ofLog() << "er gebeurt niks" << endl;
	}
	
}



void ofApp::mousePressed(int x, int y, int button){
	Ball myBall;
	myBall.setup(radius, speedX, speedY); //geeft de waardes mee zodat ik deze met de GUI kan veranderen
	balls.push_back(myBall);		//dit voegt een bal toe aan het einde van de Balls lijst. 
	
	//ter controle of de waardes van de GUI kloppen
	ofLog(OF_LOG_NOTICE)<< "waarde radius is:" << radius;
	ofLog(OF_LOG_NOTICE) << "waarde speed X is:" << speedX;
	ofLog(OF_LOG_NOTICE) << "waarde speed Y is:" << speedY;
}


