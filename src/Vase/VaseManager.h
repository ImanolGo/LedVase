/*
 *  VaseManager.h
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */


#pragma once

#include "Manager.h"


//========================== class VaseManager ==============================
//============================================================================
/** \class VaseManager VaseManager.h
 *	\brief Class managing the costume visuals
 *	\details it creates and updates the costume visuals
 */


class VaseManager: public Manager
{

    static const int NUM_HALO_LEDS;
    
    public:

        //! Constructor
        VaseManager();

        //! Destructor
        ~VaseManager();

        //! Setup the Halo Manager
        void setup();

        //! Update the Halo Manager
        void update();
    
        //! Draw the Halo Manager
        void draw();
    
    
    private:
    

       
};



