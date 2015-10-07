/*
 *  VaseManager.cpp
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */


#include "ofMain.h"

#include "VaseManager.h"
#include "AppManager.h"


VaseManager::VaseManager(): Manager()
{
	//Intentionally left empty
}


VaseManager::~VaseManager()
{
    ofLogNotice() <<"VaseManager::Destructor" ;
}


void VaseManager::setup()
{
	if(m_initialized)
		return;

    ofLogNotice() <<"VaseManager::initialized" ;
    
	Manager::setup();
    
}

void VaseManager::update()
{
    
}


void VaseManager::draw()
{
    this->drawLeds();
}

void VaseManager::drawLeds()
{
    float max = 100;
    auto ledVector = AppManager::getInstance().getLedsManager().getLeds();
    for (auto led: ledVector) {
        auto pos = led->getPosition();
        
        ofPushMatrix();
            ofTranslate(pos*100);
            led->draw();
        ofPopMatrix();
    }
}




