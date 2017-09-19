#pragma once
#include "ofMain.h"
#include "Ball.h"
#include <vector>
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

		std::vector<Ball>balls; //balls heeft meerdere Ball. dit is dus een lijst met ballen die ik later ga toepassen wanneer ik klik
		

		//dit zijn de waardes voor de GUI
		ofxPanel gui;
		ofParameter<int> radius;
		ofParameter<float>speedX;
		ofParameter<float>speedY;
		//ofParameter<ofColor>color;

		// ofParameter is lijm tussen variabele en slider
		// vector gedraagt zich als array zonder limiet
		// vector<ball>myVector; alles wat tussen '<>' staat verteld wat er in zit
		// myVector.push_back(ball); pushback plaatst een nieuw element aan het einde aan de lijst
		// myVector.pop_back(ball); haalt hem aan het einde van de lijst weer weg
		// in oF + Arduino communiceert het standardFirmata tussen de arduino en oF
		//verbinding via ofArduino class
		//KNAP - Kort Negatief, Andere Positief
};
