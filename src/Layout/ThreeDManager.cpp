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
    
    ofSetGlobalAmbientColor(ofColor(255, 255, 255));
    ofSetSmoothLighting(true);
    ofSetSphereResolution(20);
    
    this->setupManagers();
}

void ThreeDManager::setupManagers()
{
    this->setupCamera();
    this->setupLight();
    this->setupPostProcessing();
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

void ThreeDManager::setupPostProcessing()
{
    ofSetCoordHandedness(OF_RIGHT_HANDED);
    
    // Setup post-processing chain
    m_post.init(ofGetWidth(), ofGetHeight());
    
    m_post.createPass<BloomPass>()->setEnabled(true);
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
    //ofBackground(0, 0, 0);
    //ofBackgroundGradient( ofColor(80), ofColor(55), OF_GRADIENT_CIRCULAR );
    //ofBackground(20, 20, 20);
    // copy enable part of gl state
    glPushAttrib(GL_ENABLE_BIT);
    
    // setup gl state
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    m_cameraManager.begin();
    m_lightManager.enable();
    
    // begin scene to post process
    //m_post.begin(m_cameraManager.getCamera());
}

void ThreeDManager::end()
{
    m_lightManager.disable();
    m_cameraManager.end();
    
    // end scene and draw
    //m_post.end();
    
    // set gl state back to original
    glPopAttrib();
}



