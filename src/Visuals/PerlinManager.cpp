/*
 *  PerlinManager.cpp
 *  LED Costume
 *
 *  Created by Imanol Gomez on 07/10/15.
 *
 */


#include "ofMain.h"

#include "PerlinManager.h"
#include "AppManager.h"


PerlinManager::PerlinManager(): Manager(), m_noiseResolution(255), m_playNoise(true)
{
	//Intentionally left empty
}


PerlinManager::~PerlinManager()
{
    ofLogNotice() <<"PerlinManager::Destructor" ;
}


void PerlinManager::setup()
{
	if(m_initialized)
		return;


	Manager::setup();
    
    ofLogNotice() <<"PerlinManager::initialized" ;
    
}


void PerlinManager::update()
{
    if(!m_playNoise){
        return;
    }
    
    this->updateNoise();

}


void PerlinManager::updateNoise()
{
    float time = ofGetElapsedTimef() * m_noiseSpeed;
    
    auto leds = AppManager::getInstance().getLedsManager().getLeds();
    
    for (auto led: leds) {
         auto pos = led->getPosition();
         float tmpNoise = ofNoise( pos.x / m_noiseFrequency,  pos.y / m_noiseFrequency, pos.z / m_noiseFrequency, time );
        
         ofColor color;
        // the range of each of the arguments here is 0..255 so we map i and j to that range.
        
        color.setHsb( m_color.getHue(), m_color.getSaturation(), m_color.getBrightness()*tmpNoise);
        led->setColor(color);
    }
    
}


void PerlinManager::draw()
{
    if(!m_playNoise){
        return;
    }
    
}




