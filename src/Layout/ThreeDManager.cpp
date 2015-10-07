/*
 *  ThreeDManager.h
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */



#include "ThreeDManager.h"

ThreeDManager::ThreeDManager()
{
    //Intentionally left empty
}

ThreeDManager::~ThreeDManager()
{
   ofLogNotice() <<"ThreeDManager::Destructor";
}

void ThreeDManager::setup()
{
    std::cout <<"ThreeDManager::initialized" << std::endl;
    
    ofSetGlobalAmbientColor(ofColor(100, 100, 100));
    ofSetSmoothLighting(true);
    ofSetSphereResolution(20);
    
    this->setupManagers();
}

void ThreeDManager::setupManagers()
{
    this->setupCamera();
    this->setupLight();
}

void ThreeDManager::setupCamera()
{
    m_cameraManager.setup();
    m_cameraManager.setDistance(200);
}

void ThreeDManager::setupLight()
{
    m_lightManager.setup();
}



void ThreeDManager::update()
{
    m_cameraManager.update();
    m_lightManager.update();
}


void ThreeDManager::draw()
{
    m_lightManager.draw();
}



void ThreeDManager::begin()
{
    m_cameraManager.begin();
    m_lightManager.enable();
}

void ThreeDManager::end()
{
    m_lightManager.disable();
    m_cameraManager.end();
}



