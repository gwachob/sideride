#include "ofApp.h"
#include <algorithm>


//--------------------------------------------------------------
void ofApp::setup(){
    directionalDistribution = std::normal_distribution<double>(3.0,2.0);
    eitherDistribution = std::normal_distribution<double>(0.0,1.0);
    for (int x; x < 1024; x++) {
            mountainsRing[x]=1;
    }
}

int getWrapped(int length, int position, int offset) {
    return (position + length + offset) % length;
}

int clamp(int val, int lo, int hi) {
    if (val < lo) {
        return lo;
    }
    if (val > hi) {
        return hi;
    }
    return val;
}

//--------------------------------------------------------------
void ofApp::update(){
    const int SMOOTHING = 4;
    double bias = 0.00; // if we are at zero, then starting with flat ground we never have any perturbation
    int slope;
    for (int sIndex=-SMOOTHING; sIndex< 0; sIndex++) {
        {
            //cerr << "At sIndex " << sIndex;
            slope = mountainsRing[getWrapped(1024, mountainPosition, sIndex)] - mountainsRing[getWrapped(1024, mountainPosition, sIndex-1)];
            //cerr << ", slope is " << slope << "\n";
            bias += (slope*1.0)/((sIndex-1) * (sIndex-1));
        }
    }
    // clamp the bias
    if (bias > 1.5) {
        bias = 1.5;
    } else if (bias < -1.5) {
        bias = -1.5;
    }
   /* cerr << "bias is " << bias << "\n";
    if ((bias > -0.1) || (bias < 0.1)) {
        // flat ground is boring, lets artificially make it interesting
        bias = 0.1;
    }
    */
    mountainsRing[mountainPosition] = clamp(mountainsRing[getWrapped(1024, mountainPosition, -1)] + int( directionalDistribution(generator) * bias + eitherDistribution(generator)), 0, 767);
    
    /*
    int twoprev = getWrapped(1024, mountainPosition, - 2);
    int oneprev = getWrapped(1024, mountainPosition,  - 1);
    
    bool twoRising = ((mountainsRing[twoprev] < mountainsRing[oneprev]) &&
                      (mountainsRing[oneprev] < mountainsRing[mountainPosition]));
    bool twoFalling = ((mountainsRing[twoprev] > mountainsRing[oneprev]) &&
                      (mountainsRing[oneprev] > mountainsRing[mountainPosition]));
    
    if (twoRising) { // bias towards rising
        mountainsRing[mountainPosition] = clamp(mountainsRing[oneprev] + int( directionalDistribution(generator)), 0, 767);
    }
    else if (twoFalling) { // bias towards falling
        mountainsRing[mountainPosition] = clamp(mountainsRing[oneprev] - int( directionalDistribution(generator)), 0, 767);
    } else {
        mountainsRing[mountainPosition] = clamp(mountainsRing[oneprev] + int( eitherDistribution(generator)), 0, 767);
    }*/
    worldPosition += 1;
    mountainPosition = worldPosition % 1024;
    shipY = clamp(int(shipY + shipYVelocity), 0, 767);
    shipYVelocity *= 0.9;
    if ((shipYVelocity < 0.1) && (shipYVelocity > -0.1)) {
        shipYVelocity = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::sandyBrown);
    for (int x=1; x < 1024; x++) {
        //ofDrawLine(x,767-mountainsRing[getWrapped(1024, mountainPosition,x)], x-1, 767-mountainsRing[getWrapped(1024, mountainPosition-1,x)]);
        //ofDrawRectangle(x,767-mountainsRing[getWrapped(1024, mountainPosition,x)], 1, 1);
        ofDrawRectangle(x,767-mountainsRing[getWrapped(1024, mountainPosition,x)], 1, mountainsRing[getWrapped(1024, mountainPosition,x)]);
    }
    ofSetColor(ofColor::royalBlue);
    
    ofDrawSphere(300, shipY, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key ==  'w') {
        shipYVelocity -= 5.0;
    } else if (key == 's') {
        shipYVelocity += 5.0;
    }
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
