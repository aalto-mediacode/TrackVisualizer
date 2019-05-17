#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(10);
    ofSetCircleResolution(100);
    ofSetBackgroundAuto(true);
    
    // Load songs and play track [1]
    mySong1.load("Jupiter.mp3");
    mySong2.load("Manuvers.mp3");
    mySong3.load("PullUp.mp3");
    mySong1.play();

    mySong1.setMultiPlay(false);
    mySong2.setMultiPlay(false);
    mySong3.setMultiPlay(false);
    
    // Gravity point settings
    origin = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    gravityPoint = ofVec2f(origin);
    speed.set(0, 0);
    pos = ofVec2f(origin);
    maxSpeed = 35;

}

//--------------------------------------------------------------
void ofApp::update(){
    spectrum = ofSoundGetSpectrum(NUM_CIRCLES);
    
    // To prevent jitter - when pos gets closer to gravityPoint, speed slows down
    if (gravityPoint.distance(pos) < 200) {
        speed*=0.95;
    }
    
    // The greater the distance between gravityPoint and pos, the greater the acceleration
    acceleration.set((gravityPoint.x - pos.x)/60, (gravityPoint.y - pos.y)/60);
    speed += acceleration;
    speed.limit(maxSpeed);
    pos += speed;
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < NUM_CIRCLES; i++) {
        ofSetColor(ofMap(i, 0, NUM_CIRCLES, 255, 0), ofRandom(0, 255), ofMap(i, 0, NUM_CIRCLES, 255, 0));
        if (i > 400) ofDrawCircle(pos, 15 * spectrum[i] * (i/32+ 1));
        else ofDrawCircle(pos, 15 * spectrum[i] * (i/16+ 1));
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Toggling tracks
    if (key == '1') {
        mySong1.play();
        mySong2.stop();
        mySong3.stop();
        ofBackground(10);
        speed.set(0, 0);
        gravityPoint.set(origin);
        pos.set(origin);
        ofSetBackgroundAuto(true);
    }
    if (key == '2') {
        mySong1.stop();
        mySong2.play();
        mySong3.stop();
        ofBackground(10);
        speed.set(0, 0);
        gravityPoint.set(origin);
        pos.set(origin);
        ofSetBackgroundAuto(true);
    }
    if (key == '3') {
        mySong1.stop();
        mySong2.stop();
        mySong3.play();
        ofBackground(10);
        speed.set(0, 0);
        gravityPoint.set(origin);
        pos.set(origin);
        ofSetBackgroundAuto(true);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}
//--------------------------------------------------------------

void ofApp::mouseDragged(int x, int y, int button){
    // Circles follow mouse
    gravityPoint.set(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // Circles follow mouse
    gravityPoint.set(ofGetMouseX(), ofGetMouseY());
    ofSetBackgroundAuto(false);
}
//--------------------------------------------------------------

void ofApp::mouseReleased(int x, int y, int button){
    // Circles return to origin
    gravityPoint.set(origin);
//    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){}
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){}
