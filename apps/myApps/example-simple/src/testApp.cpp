#include "testApp.h"

#include "ofxBt.h"

ofxBt::World world;

ofxBt::RigidBody center_box;
vector<ofxBt::RigidBody> boxes;

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);

	ofBackground(30);

	world.setup(ofVec3f(0, 0, 0));

	for (int i = 0; i < 100; i++)
	{
		ofxBt::RigidBody o = world.addBox(ofVec3f(10, 10, 10), ofVec3f(ofRandom(-5, 5), i * 2, ofRandom(-5, 5)));
		o.setMass(0.1);
		boxes.push_back(o);
	}

	center_box = world.addBox(ofVec3f(50, 50, 50), ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	center_box.setStatic(true);
	center_box.setMass(0);

	// world.addPlane(ofVec3f(0, 1, 0), ofVec3f(0, 0, 0));
	// world.addWorldBox(ofVec3f(-50, -50, -50), ofVec3f(50, 50, 50));
}

//--------------------------------------------------------------
void testApp::update()
{
	world.update();

	float s = fabs(sin(ofGetElapsedTimef() * 3));
	s = pow(s, 32);
	s = s * 30 + 50;
	center_box.setSize(ofVec3f(s, s, s));
	center_box.applyForce(ofVec3f(10, 2, 3));

	for (int i = 0; i < boxes.size(); i++)
	{
		boxes[i].applyForce(boxes[i].getPosition().normalized() * -10);
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	cam.begin();
	
	world.draw();

	cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}