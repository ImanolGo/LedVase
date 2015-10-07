/*
 *  3DManager.h
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */


#pragma once

#include "CameraManager.h"
#include "LightManager.h"
#include "Manager.h"

#include "ofxPostProcessing.h"

//========================== class ThreeDManager =======================================
//==============================================================================
/** \class ThreeDManager ThreeDManager.h
 *	\brief class for controlling the 3D virtual world
 *	\details ...
 */




class ThreeDManager: public Manager
{

public:
    //! Constructor
    ThreeDManager();

    //! Destructor
    virtual ~ThreeDManager();

    //! setups the 3D environment
    void setup();

    //! updates the 3D environment
    void update();

    //! draws the 3D environment
    void draw();

     //! begin the 3D environment
    void begin();

     //! end the 3D environment
    void end();

protected:

    //! setups the managers
    void setupManagers();
    //! setups the camera
    void setupCamera();
    
    //! setups the light
    void setupLight();
    
    //! setups the post processing effects
    void setupPostProcessing();


protected:


    LightManager               m_lightManager;         ///< manages and renders all visuals
    CameraManager              m_cameraManager;        ///< manages and renders the cube-sphere

    ofxPostProcessing          m_post;
 };

