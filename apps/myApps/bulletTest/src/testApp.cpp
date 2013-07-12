#include "testApp.h"
#include "ofxBt.h"

ofxBt::World world;
vector<ofxBt::RigidBody> boxes;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    ofBackground(0);
    
    world.setup(ofVec3f(0, -98, 0));
    
    for(int i = 0; i < 1000; i++){
        ofxBt::RigidBody o = world.addBox(ofVec3f(10, 10, 10), ofVec3f(ofRandom(-5, 5), i * 2, ofRandom(-5, 5)));
        o.setMass(0.1);
        boxes.push_back(o);
    }
    
    world.addPlane(ofVec3f(0, 1, 0), ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void testApp::update(){
    world.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    cam.begin();
    world.draw();
    cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}