#pragma once

#include "ofMain.h"
#include <random>

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
		
private:
    int mountainsRing[1024];
    int mountainPosition=0; // Position in the ring mountain ring buffer representing the left most position on the screen (world position 0)
    long worldPosition = 0L; // Position of world the left most screen position is
    int positionX = 511;
    int positionY = 383;
    int shipY = 100;
    double shipYVelocity = 0;
    std::default_random_engine generator;
    std::normal_distribution<double> directionalDistribution;
    std::normal_distribution<double> eitherDistribution;
};
