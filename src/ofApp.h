#pragma once

#include "ofMain.h"

#define NUM_CIRCLES 512

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
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
		
    ofSoundPlayer mySong1, mySong2, mySong3;
    float *spectrum;
    ofVec2f gravityPoint, origin, mouse;
    ofVec2f pos, speed, acceleration;
    float angle;
    float maxSpeed;
};
