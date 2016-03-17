/*
 *  AppManager.h
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */

#pragma once

#include "ofMain.h"

#include "Manager.h"

#include "SettingsManager.h"
#include "GuiManager.h"
#include "ResourceManager.h"
#include "VisualEffectsManager.h"
#include "ViewManager.h"
#include "VaseManager.h"
#include "LedsManager.h"
#include "ThreeDManager.h"
#include "LayoutManager.h"
#include "PerlinManager.h"
#include "AnimationsManager.h"
#include "ImageManager.h"
#include "VideoManager.h"


//========================== class AppManager ==============================
//============================================================================
/** \class AppManager AppManager.h
 *	\brief Class managing the whole application
 *	\details it set-ups, updates and renders all the different managers used for the application
 */

class AppManager: public Manager
{
public:

    //! Destructor
    ~AppManager();

    //! Returns the singleton instance.
    static AppManager& getInstance();

    //! Compares two transition objects
    void setup();

    //! updates the logic
    void update();

    //! calls the view manager to draw
    void draw();

    //==========================================================================

    //! Returns the settings manager
    SettingsManager& getSettingsManager() { return m_settingsManager; }

    //! Returns the GUI manager
    GuiManager& getGuiManager() { return m_guiManager; }

    //! Returns the resource manager
    ResourceManager&  getResourceManager() { return m_resourceManager; }

    //! Returns the view manager
    ViewManager&  getViewManager() { return m_viewManager; }

    //! Returns the visual effects manager
    VisualEffectsManager&  getVisualEffectsManager() { return m_visualEffectsManager; }

    //! Returns the LEDs manager
    LedsManager&   getLedsManager() { return m_ledsManager; }

    //! Returns the vase manager
    VaseManager&   getVaseManager() { return m_vaseManager; }

    //! Returns the 3D manager
    ThreeDManager&   getThreeDManager() { return m_threeDManager; }

    //! Returns the Layout manager
    LayoutManager&   getLayoutManager() { return m_layoutManager; }

    //! Returns the Perlin manager
    PerlinManager&   getPerlinManager() { return m_perlinManager; }

    //! Returns the Image manager
    ImageManager&   getImageManager() { return m_imageManager; }

    //! Returns the animations manager
    AnimationsManager&   getAnimationsManager() { return m_animationsManager; }

    //! Returns the video manager
    VideoManager&   getVideoManager() { return m_videoManager; }



    //==========================================================================

    void toggleDebugMode();

    void setDebugMode(bool showDebug);


private:

     //! Constructor
     AppManager();

	//! Stop the compiler generating methods of copy the object
	 AppManager(AppManager const& copy);              // Don't Implement

    //! Prevent operator= being generated.
     AppManager& operator=(AppManager const& copy);     // Don't implement

    //==========================================================================

    //! Set-up all the managers
    void setupManagers();

    //! Set-up openFrameworks
    void setupOF();

    //! update all the managers
    void updateManagers();

private:


    SettingsManager          m_settingsManager;          ///< Manages the application's settings
    GuiManager               m_guiManager;               ///< Manages the application's settings
    ResourceManager          m_resourceManager;          ///< Manages the resources
    ViewManager              m_viewManager;              ///< Manages the visuals
    VisualEffectsManager     m_visualEffectsManager;     ///< Manages the visual effects
    VaseManager              m_vaseManager;              ///< Manages the vase's visuals
    LedsManager              m_ledsManager;              ///< Manages the vase's leds
    ThreeDManager            m_threeDManager;            ///< Manages the 3D System
    PerlinManager            m_perlinManager;            ///< Manages the Perlin Noise Visuals
    LayoutManager            m_layoutManager;            ///< Manages the Layout
    ImageManager             m_imageManager;             ///< Manages the images to be exported
    AnimationsManager        m_animationsManager;         ///< Manages the animations to visualize
    VideoManager             m_videoManager;             ///< Manages the video  visuals

    bool                     m_debugMode;
};

//==========================================================================
