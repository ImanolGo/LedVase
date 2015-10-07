/*
 *  LightManager.h
 *
 *  Created by Imanol Gomez on 23/02/15.
 *
 */

#include "LightManager.h"


const float LightManager::NEAR_DISTANCE = 1050;
const float LightManager::FAR_DISTANCE = 10500;

LightManager::LightManager():Manager()
{
    //Intentionally left empty
}

LightManager::~LightManager()
{
    ofLogNotice() << "LightManager::destructor";
}

//--------------------------------------------------------------
void LightManager::setup()
{
    if(m_initialized)
        return;
    
    ofLogNotice() <<"LightManager::initialized";
    
     this->setLights();
    
     // light the scene to show off why normals are important
    //this->enable();
}

void LightManager::setLights()
{
    
    ofPtr<ofLight> light = ofPtr<ofLight> (new ofLight());
    light->setDiffuseColor( ofFloatColor(.85, .85, .55) );
    light->setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    m_lights["pointLight1"] = light;
    
    light = ofPtr<ofLight> (new ofLight());
    light->setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    light->setSpecularColor( ofFloatColor(.8f, .8f, .9f));
    m_lights["pointLight2"] = light;
    
    light = ofPtr<ofLight> (new ofLight());
    light->setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    m_lights["pointLight3"] = light;

}

void LightManager::update()
{
   //Here comes some light animations
}

void LightManager::enable()
{
    ofEnableLighting();
    for(LightMap::iterator it = m_lights.begin(); it!=m_lights.end(); ++it){
        it->second->enable();
    }
}

void LightManager::disable()
{
    ofDisableLighting();
    for(LightMap::iterator it = m_lights.begin(); it!=m_lights.end(); ++it){
        it->second->disable();
    }
}


void LightManager::draw()
{
    ofPushMatrix();

        for(LightMap::iterator it = m_lights.begin(); it!=m_lights.end(); ++it){
            it->second->draw();
        }

    ofPopMatrix();
}






