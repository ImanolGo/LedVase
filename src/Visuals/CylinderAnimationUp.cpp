/*
 *  CylinderAnimationUp.cpp
 *  Cirque du Soleil Dress
 *
 *  Created by Imanol Gomez on 09/02/16.
 *
 */


#include "ofMain.h"

#include "CylinderAnimationUp.h"

#include "AppManager.h"




CylinderAnimationUp::CylinderAnimationUp(): m_numFrames(0), m_currentFrame(0)
{
	//Intentionally left empty
}


CylinderAnimationUp::~CylinderAnimationUp()
{
    ofLogNotice() <<"CylinderAnimationUp::Destructor" ;
}


void CylinderAnimationUp::setup()
{
    this->setupNumFrames();
}


void CylinderAnimationUp::setupNumFrames()
{
    float fps =  24;
    float animationTimeInS = 1;

    m_numFrames = animationTimeInS*fps;

}


void CylinderAnimationUp::setupEffect()
{
    //ofPtr<MoveVisual> visual = ofPtr<BasicVisual>(new BasicVisual());
    //m_moveEffect = ofPtr<MoveVisual>(new MoveVisual(visual));
}

void CylinderAnimationUp::update()
{

    m_currentFrame = (m_currentFrame + 1)%m_numFrames;
    //ofLogNotice() <<"CylinderAnimationUp::update-> current frame " << m_currentFrame;
}

void CylinderAnimationUp::draw()
{
   ///Draw
}
