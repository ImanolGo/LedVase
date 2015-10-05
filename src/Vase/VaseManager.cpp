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


	Manager::setup();
    
    ofLogNotice() <<"VaseManager::initialized" ;
    
}


void VaseManager::update()
{
    
}


void VaseManager::draw()
{
    
}



