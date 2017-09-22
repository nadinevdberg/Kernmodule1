#pragma once
#include "ofMain.h"
using namespace std;
#include "Ball.h"
#include <vector>
#include "ofEvents.h"

//---------------------------------------------------------------


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		vector<Ball>balls;
private:

	//arduino communicatie class
	ofArduino arduino;

	// wordt aangeroepen zodra arduino klaar is met opstarten
	void setupArduino(const int& version);

	// is de waarde van een analoge pin veranderd?
	void analogPinChanged(const int & pin);

	// is de waarde van een digitale pin veranderd?
	void digitalPinChanged(const int & pin);


		
};
/*		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		*/