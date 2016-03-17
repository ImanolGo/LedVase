/*
 *  CylinderAnimationUp.h
 *  Cirque du Soleil Dress
 *
 *  Created by Imanol Gomez on 09/02/16.
 *
 */


#pragma once


//========================== class CylinderAnimationUp ==============================
//============================================================================
/** \class CylinderAnimationUp CylinderAnimationUp.h
 *	\brief Class representing cylinder like animations going up
 *	\details it creates and updates the cylinder animations
 */

#include "LedsManager.h"
#include "VisualEffects.h"

class CylinderAnimationUp
{

    public:

        //! Constructor
        CylinderAnimationUp();

        //! Destructor
        ~CylinderAnimationUp();

        //! Setup the Audio Equalizer
        void setup();

        //! Update the Audio Equalizer
        void update();

        //! Draw the Audio Equalizer
        void draw();

    private:

        void setupNumFrames();
    
        void setupEffect();

    private:

        int m_numFrames;
        int m_currentFrame;
    
        ofPtr<MoveVisual>     m_moveEffect;
};
