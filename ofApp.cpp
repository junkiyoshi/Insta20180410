#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(139);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofPoint start = ofPoint(0, ofNoise(11, ofGetFrameNum() * 0.01) * ofGetHeight());
	ofPoint end = ofPoint(ofGetWidth(), ofNoise(3, ofGetFrameNum() * 0.01) * ofGetHeight());
	ofPoint distance = end - start;

	float radius = 72;
	bool flag = true;
	for (int circle_x = radius; circle_x < ofGetWidth() + radius; circle_x += radius * 2) {

		for (int circle_y = radius; circle_y < ofGetHeight() + radius; circle_y += radius * 2) {

			flag ? ofSetColor(39) : ofSetColor(239);

			ofBeginShape();
			for (int deg = 0; deg < 360; deg++) {

				float x = radius * cos(deg * DEG_TO_RAD) + circle_x;
				float y = radius * sin(deg * DEG_TO_RAD) + circle_y;
				ofPoint point = start + (distance / ofGetWidth()) * x;
				if (y > point.y) {

					flag ? ofVertex(x, y) : ofVertex(point);
				}
				else {

					flag ? ofVertex(point) : ofVertex(x, y);
				}
			}
			ofEndShape(true);

			flag = !flag;
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}