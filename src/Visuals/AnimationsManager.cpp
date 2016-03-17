/*
 *  AnimationsManager.cpp
 *  Cirque du Soleil Dress
 *
 *  Created by Imanol Gomez on 09/02/16.
 *
 */


#include "ofMain.h"

#include "AnimationsManager.h"
#include "AppManager.h"


const int AnimationsManager::NUMBER_VISUALS = 1;
const int AnimationsManager::FBO_WIDTH = 1030;
const int AnimationsManager::FBO_HEIGHT = 524;

AnimationsManager::AnimationsManager(): Manager(), m_playAnimations(false), m_mode(0)
{
	//Intentionally left empty
}


AnimationsManager::~AnimationsManager()
{
    ofLogNotice() <<"AnimationsManager::Destructor" ;
}


void AnimationsManager::setup()
{
	if(m_initialized)
		return;


	Manager::setup();

    this->setupBoundingBox();
    this->setupFbo();
    this->setupCylinder();
    this->setupShader();

    ofLogNotice() <<"AnimationsManager::initialized" ;

}

void AnimationsManager::setupBoundingBox()
{
    float ratio = ((float)ofGetWidth())/ofGetHeight();

    m_boundingBox.width = AppManager::getInstance().getGuiManager().getWidth();
    m_boundingBox.height = m_boundingBox.width/ratio;


    m_boundingBox.y = AppManager::getInstance().getGuiManager().getPosition().y + AppManager::getInstance().getGuiManager().getHeight() + 20;
    m_boundingBox.x = AppManager::getInstance().getGuiManager().getPosition().x;
}



void AnimationsManager::setupFbo()
{
    m_fbo.allocate(FBO_WIDTH, FBO_HEIGHT,GL_RGBA32F_ARB);
    m_fbo.begin(); ofClear(0); m_fbo.end();
}

void AnimationsManager::setupShader()
{
    m_shader.setGeometryInputType(GL_LINES);
    m_shader.setGeometryOutputType(GL_TRIANGLE_STRIP);
    m_shader.setGeometryOutputCount(4);
    m_shader.load("shaders/ThickLineShaderVert.glsl", "shaders/ThickLineShaderFrag.glsl", "shaders/ThickLineShaderGeom.glsl");
}

void AnimationsManager::resetPosition()
{
    setupBoundingBox();
}

void AnimationsManager::setupCylinder()
{
    m_cylinderAnimation.setup();
}



void AnimationsManager::update()
{
    if (!m_playAnimations) {
        return;
    }

    
    switch (m_mode)
    {
        case 0:
            this->updateCylinder();
            break;
        default:
            break;
    }

    this->updateFbo();
}



void AnimationsManager::updateCylinder()
{
    m_cylinderAnimation.update();
}



void AnimationsManager::updateFbo()
{

    ofEnableAlphaBlending();
    m_fbo.begin();

        switch (m_mode)
        {
            case 0:
                this->drawCylinder();
                break;
          
            default:
                break;
        }

    m_fbo.end();
    ofDisableAlphaBlending();

    ofPixels pixels;
    m_fbo.readToPixels(pixels);

    AppManager::getInstance().getLedsManager().setPixels(pixels);
}

void AnimationsManager::drawCylinder()
{
    ofPushStyle();
    ofFill();
    ofSetColor(0,0,0,40);
    ofRect(0,0,m_fbo.getWidth(),m_fbo.getHeight());

    m_shader.begin();
    m_shader.setUniform1f("thickness", 2);

    m_cylinderAnimation.draw();

    ofPopStyle();
    m_shader.end();
}




void AnimationsManager::draw()
{
    if (!m_playAnimations) {
        return;
    }

    m_fbo.draw(m_boundingBox);
}

void AnimationsManager::onPlayAnimationsChange(bool value)
{
    m_playAnimations = value;
}

