/*
 *  LedVaseApp.cpp
 *  LED Egg
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */

#include "AppManager.h"

#include "LedVaseApp.h"

//--------------------------------------------------------------
void LedVaseApp::setup(){
    AppManager::getInstance().setup();
}

//--------------------------------------------------------------
void LedVaseApp::update(){
    AppManager::getInstance().update();
}

//--------------------------------------------------------------
void LedVaseApp::draw(){
    AppManager::getInstance().draw();
}

void LedVaseApp::exit()
{
    ofLogNotice() <<"LedVaseApp::exit";

}

//--------------------------------------------------------------
void LedVaseApp::keyPressed(int key){

}

//--------------------------------------------------------------
void LedVaseApp::keyReleased(int key){

}

//--------------------------------------------------------------
void LedVaseApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void LedVaseApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void LedVaseApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void LedVaseApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void LedVaseApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void LedVaseApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void LedVaseApp::dragEvent(ofDragInfo dragInfo){

}
