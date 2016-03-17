/*
 *  GuiManager.cpp
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */

#include "ofMain.h"

#include "AppManager.h"

#include "GuiManager.h"


const string GuiManager::GUI_SETTINGS_FILE_NAME = "xmls/GuiSettings.xml";
const string GuiManager::GUI_SETTINGS_NAME = "LedVase";
const int GuiManager::GUI_WIDTH = 350;


GuiManager::GuiManager(): Manager(), m_showGui(true)
{
	//Intentionally left empty
}


GuiManager::~GuiManager()
{
    this->saveGuiValues();
    ofLogNotice() <<"GuiManager::Destructor";
}


void GuiManager::setup()
{
	if(m_initialized)
		return;
    
    Manager::setup();


    this->setupGuiParameters();
    this->setupModesGui();
    this->setupLayoutGui();
    this->setupImageGui();
    this->setupVideoGui();
    this->setupPerlinGui();
    this->loadGuiValues();
    
    ofLogNotice() <<"GuiManager::initialized";
    
}

void GuiManager::setupGuiParameters()
{
    m_gui.setDefaultWidth(GUI_WIDTH);
    m_gui.setup(GUI_SETTINGS_NAME, GUI_SETTINGS_FILE_NAME);
    m_gui.setPosition(ofGetWidth() - GUI_WIDTH - 20, 40);
    //m_gui.setPosition(20, 20);
    m_gui.add(m_guiFPS.set("FPS", 0, 0, 60));
    ofxGuiSetFont( "fonts/open-sans/OpenSans-Semibold.ttf", 9 );
}


void GuiManager::setupModesGui()
{
    
    m_parametersModes.setName("Modes");
    
    m_videoMode.set("Video",  false );
    m_videoMode.addListener(this, &GuiManager::onSetVideoMode);
    m_parametersModes.add(m_videoMode);
    
    m_perlinMode.set("Perlin",  false );
    m_perlinMode.addListener(this, &GuiManager::onSetPerlinMode);
    m_parametersModes.add(m_perlinMode);
    
    m_animationMode.set("Animations",  false );
    m_animationMode.addListener(this, &GuiManager::onSetAnimationMode);
    m_parametersModes.add(m_animationMode);
    
    m_gui.add(m_parametersModes);
}

void GuiManager::setupLayoutGui()
{
    auto layoutManager = &AppManager::getInstance().getLayoutManager();
    
    m_parametersLayout.setName("Color");
    
    m_hue.set("Hue", 0.0, 0.0, 255.0);
    m_hue.addListener(layoutManager, &LayoutManager::onHueChange);
    m_parametersLayout.add(m_hue);
    
    m_saturation.set("Saturation", 0.0, 0.0, 255.0);
    m_saturation.addListener(layoutManager, &LayoutManager::onSaturationChange);
    m_parametersLayout.add(m_saturation);
    
    m_brightness.set("Brightness", 0.0, 0.0, 255.0);
    m_brightness.addListener(layoutManager, &LayoutManager::onBrightnessChange);
    m_parametersLayout.add(m_brightness);
    
    m_gui.add(m_parametersLayout);
}

void GuiManager::setupImageGui()
{
    auto imageManager = &AppManager::getInstance().getImageManager();
    
    m_parametersImage.setName("Image Export");
    
    m_imageRecord.set("Record",  false );
    m_imageRecord.addListener(imageManager, &ImageManager::onRecordingChange);
    m_parametersImage.add(m_imageRecord);
    
    m_imageMirror.set("Mirror",  false );
    m_imageMirror.addListener(imageManager, &ImageManager::onMirroringChange);
    m_parametersImage.add(m_imageMirror);
    
    
    m_gui.add(m_parametersImage);
}

void GuiManager::setupVideoGui()
{
    auto videoManager = &AppManager::getInstance().getVideoManager();
    
    m_parametersVideo.setName("Video");
    
    m_nextVideo.setup("Next Video");
    m_nextVideo.addListener(videoManager, &VideoManager::onNextVideoChange);
    
    
    m_recordVideoLoops.set("Record Video Loops", false);
    m_recordVideoLoops.addListener(videoManager, &VideoManager::onRecordVideoLoopsChange);
    m_parametersVideo.add(m_recordVideoLoops);
    
    m_gui.add(m_parametersVideo);
    m_gui.add(&m_nextVideo);
    
}

void GuiManager::setupPerlinGui()
{
    auto perlinManager = &AppManager::getInstance().getPerlinManager();
    
    m_parametersPerlin.setName("Perlin Visuals");
    
    m_perlinFrequency.set("Perlin Frequency",  0.4, 0.0, 4.0);
    m_perlinFrequency.addListener(perlinManager, &PerlinManager::onNoiseFrequencyChange);
    m_parametersPerlin.add(m_perlinFrequency);
    
    m_perlinSpeed.set("Perlin Speed",  1.0, 0.001, 3);
    m_perlinSpeed.addListener(perlinManager, &PerlinManager::onNoiseSpeedChange);
    m_parametersPerlin.add(m_perlinSpeed);
    
    m_gui.add(m_parametersPerlin);
}



void GuiManager::draw()
{
    if(!m_showGui)
        return;
    
    m_guiFPS = ofGetFrameRate();
    m_gui.draw();
    
}


void GuiManager::saveGuiValues()
{
    m_gui.saveToFile(GUI_SETTINGS_FILE_NAME);
}

void GuiManager::loadGuiValues()
{
    m_gui.loadFromFile(GUI_SETTINGS_FILE_NAME);
}


void GuiManager::toggleGui()
{
    m_showGui = !m_showGui;
}


void GuiManager::onSetPerlinMode(bool& value)
{
    if(value == true){
        m_animationMode = false;
        m_videoMode = false;
        AppManager::getInstance().getVideoManager().onPlayVideoChange(false);
        AppManager::getInstance().getPerlinManager().onPlayNoiseChange(true);
        AppManager::getInstance().getAnimationsManager().onPlayAnimationsChange(false);
    }
}

void GuiManager::onSetAnimationMode(bool& value)
{
    if(value == true){
        m_perlinMode = false;
        m_videoMode = false;
        AppManager::getInstance().getVideoManager().onPlayVideoChange(false);
        AppManager::getInstance().getPerlinManager().onPlayNoiseChange(false);
        AppManager::getInstance().getAnimationsManager().onPlayAnimationsChange(true);
    }
    
}

void GuiManager::onSetVideoMode(bool& value)
{
    if(value == true){
        m_perlinMode = false;
        m_animationMode = false;
        AppManager::getInstance().getVideoManager().onPlayVideoChange(true);
        AppManager::getInstance().getPerlinManager().onPlayNoiseChange(false);
        AppManager::getInstance().getAnimationsManager().onPlayAnimationsChange(false);
    }
    
}



