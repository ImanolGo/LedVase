/*
 *  GuiManager.h
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */

#pragma once

#include "Manager.h"
#include "ofxGui.h"
//========================== class GuiManager ==============================
//============================================================================
/** \class GuiManager GuiManager.h
 *	\brief Class managing the application´s grapical user interface (GUI)
 *	\details It creates the gui and the callback functions that will be affected
 *    by the gui
 */

class GuiManager: public Manager
{
    static const string GUI_SETTINGS_FILE_NAME;
    static const string GUI_SETTINGS_NAME;
    static const int GUI_WIDTH;
    
public:

    //! Constructor
    GuiManager();

    //! Destructor
    ~GuiManager();

    //! Set-up the gui
    void setup();
    
    //! Draw the gui
    void draw();
    
    void saveGuiValues();
    
    void loadGuiValues();
    
    void toggleGui();
    
    void showGui(bool show){m_showGui=show;}
    
    int getWidth() {return GUI_WIDTH;}
    
    int getHeight() {return m_gui.getHeight();}
    
    ofPoint  getPosition() {return m_gui.getPosition();}
    
private:
    
    void setupGuiParameters();
    
    void setupPerlinGui();
    
    void setupLayoutGui();


private:
    
    // Fluid GUI
    ofxPanel			m_gui;
    
    ofParameter<float>	m_guiFPS;
    
    ofParameterGroup    m_parametersPerlin;
    ofParameterGroup    m_parametersLayout;
    
    ofParameter<float>    m_perlinFrequency;
    ofParameter<float>    m_perlinSpeed;
    
    ofParameter<float>      m_hue;
    ofParameter<float>      m_brightness;
    ofParameter<float>      m_saturation;
    
   
    bool        m_showGui;  //It defines the whether the gui should be shown or not
};

//==========================================================================


