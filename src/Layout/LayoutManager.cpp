/*
 *  LayoutManager.cpp
 *  Led Costume
 *
 *  Created by Imanol Gomez on 07/10/15.
 *
 */

#include "ofMain.h"

#include "AppManager.h"
#include "SettingsManager.h"
#include "ViewManager.h"


#include "LayoutManager.h"

LayoutManager::LayoutManager(): Manager()
{
	//Intentionally left empty
}


LayoutManager::~LayoutManager()
{
    ofLogNotice() <<"LayoutManager::Destructor";
}


void LayoutManager::setup()
{
	if(m_initialized)
		return;

    ofLogNotice() <<"LayoutManager::initialized";

	Manager::setup();

    this->createTextVisuals();
    this->createImageVisuals();

    this->addVisuals();

}


void LayoutManager::createTextVisuals()
{
    ///To implement in case we have text visuals
}

void LayoutManager::createImageVisuals()
{
    //this->createBackground();
}

void LayoutManager::createBackground()
{
}

void LayoutManager::addVisuals()
{
    int depthLevel = -1;
    
    for(TextMap::iterator it = m_textVisuals.begin(); it!= m_textVisuals.end(); ++it){
        AppManager::getInstance().getViewManager().addOverlay(it->second,depthLevel);
    }
    
    for(ImageMap::iterator it = m_imageVisuals.begin(); it!= m_imageVisuals.end(); ++it){
        AppManager::getInstance().getViewManager().addOverlay(it->second,depthLevel);
    }
}


void LayoutManager::onHueChange(float& value)
{
    //AppManager::getInstance().getVideoManager().onBrightnessChange(value);
    AppManager::getInstance().getPerlinManager().onHueChange(value);
}

void LayoutManager::onBrightnessChange(float& value)
{
    //AppManager::getInstance().getVideoManager().onBrightnessChange(value);
    AppManager::getInstance().getPerlinManager().onBrightnessChange(value);
}

void LayoutManager::onSaturationChange(float& value)
{
    //AppManager::getInstance().getVideoManager().onSaturationChange(value);
    AppManager::getInstance().getPerlinManager().onSaturationChange(value);
}



