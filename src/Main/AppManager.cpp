/*
 *  AppManager.cpp
 *  Led Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */

#include "ofMain.h"


#include "AppManager.h"

AppManager& AppManager::getInstance()
{
	// The only instance
	// Guaranteed to be lazy initialized
	// Guaranteed that it will be destroyed correctly
	static AppManager    m_instance;
    return m_instance;

}

AppManager::AppManager(): Manager(), m_debugMode(false)
{
   //Intentionally left empty
}


AppManager::~AppManager()
{
    ofLogNotice() <<"AppManager::Destructor";
}


void AppManager::setup()
{
	if(m_initialized)
		return;

    //ofSetDataPathRoot("../Resources/data/");
    
    ofLogNotice() << "AppManager::initialized";

	Manager::setup();
    
    this->setupOF();
	this->setupManagers();
    
    //setDebugMode(m_debugMode);
}

void AppManager::setupOF()
{
    ofSetLogLevel(OF_LOG_NOTICE);
    //ofSetFrameRate(24);
    ofSetVerticalSync(true);
    ofSetEscapeQuitsApp(true);
}


void AppManager::setupManagers()
{
    m_viewManager.setup();
    m_visualEffectsManager.setup();
    m_settingsManager.setup();
    m_resourceManager.setup();
    m_threeDManager.setup();
    m_layoutManager.setup();
    m_perlinManager.setup();
    m_ledsManager.setup();
    m_vaseManager.setup();
    
    m_guiManager.setup();
    
}

void AppManager::update()
{
    
    m_visualEffectsManager.update();
    m_viewManager.update();
    m_perlinManager.update();
    m_ledsManager.update();
    m_vaseManager.update();
    m_threeDManager.update();
}


void AppManager::draw()
{
    
    ofBackgroundGradient( ofColor(80), ofColor(55), OF_GRADIENT_CIRCULAR );
    
    m_threeDManager.begin();
        m_vaseManager.draw();
    m_threeDManager.end();
    
    m_viewManager.draw();
    
    m_guiManager.draw();
    
}

void AppManager::toggleDebugMode()
{
    m_debugMode = !m_debugMode;
    setDebugMode(m_debugMode);
}


void AppManager::setDebugMode(bool showDebug)
{
    m_debugMode = showDebug;
    
    ofLogNotice()<<"AppManager::setDebugMode-> " << m_debugMode;
    
    if(m_debugMode){
        //ofSetLogLevel(OF_LOG_VERBOSE);
    }
    else{
        ofSetLogLevel(OF_LOG_NOTICE);
    }
    
    
}



