/*
 *  PerlinManager.h
 *  LED Vase
 *
 *  Created by Imanol Gomez on 07/10/15.
 *
 */


#pragma once

#include "Manager.h"


//========================== class PerlinManager ==============================
//============================================================================
/** \class PerlinManager PerlinManager.h
 *	\brief Class managing the perlin noise visuals
 *	\details it creates and updates perlin noise visuals, as well it provides methods to change it in real time
 */


class PerlinManager: public Manager
{
    
    public:

        //! Constructor
        PerlinManager();

        //! Destructor
        ~PerlinManager();

        //! Setup the Perlin Manager
        void setup();

        //! Update the Perlin Manager
        void update();
    
        //! Draw the Perlin Manager
        void draw();
    
        void onNoiseFrequencyChange(float& value) {m_noiseFrequency = value;}
    
        void onNoiseSpeedChange(float& value) {m_noiseSpeed = value;}
    
        void onHueChange(float& value) {m_color.setHue(value);}
    
        void onBrightnessChange(float& value) {m_color.setBrightness(value);}
    
        void onSaturationChange(float& value) {m_color.setSaturation(value);}
    
        void  onPlayNoiseChange(bool value) {m_playNoise = value;}
    
    private:
    
        void updateNoise();
    
    
    private:
  
        float       m_noiseFrequency;
        float       m_noiseSpeed;
        int         m_noiseResolution;
    
        ofColor     m_color;
        bool        m_playNoise;
};




