/*
 *  AnimationsManager.h
 *  Cirque du Soleil Dress
 *
 *  Created by Imanol Gomez on 09/02/16.
 *
 */


#pragma once

#include "Manager.h"

#include "CylinderAnimationUp.h"



//========================== class AnimationsManager ==============================
//============================================================================
/** \class AnimationsManager AnimationsManager.h
 *	\brief Class managing the audio reactive visuals
 *	\details it creates and updates the audio reactive visuals
 */


class AnimationsManager: public Manager
{

    static const int NUMBER_VISUALS;

    public:

        //! Constructor
        AnimationsManager();

        //! Destructor
        ~AnimationsManager();

        //! Setup the Video Manager
        void setup();

        //! Update the Video Manager
        void update();

        //! Draw the Video Manager
        void draw();

        void  onPlayAnimationsChange(bool value);

        void resetPosition();


    private:

        void setupBoundingBox();

        void setupFbo();

        void setupShader();

        void setupCylinder();

        void updateFbo();

        void updateCylinder();

        void drawCylinder();


    public:

        static const int FBO_WIDTH;
        static const int FBO_HEIGHT;

    private:

        bool            m_playAnimations;
        ofRectangle     m_boundingBox;
        int             m_mode;

        CylinderAnimationUp  m_cylinderAnimation;

        ofFbo               m_fbo;
        ofShader            m_shader;

};
