/*
 *  VaseManager.h
 *  Led Vase
 *
 *  Created by Imanol Gomez on 17/03/16.
 *
 */


#pragma once

#include "Manager.h"


//========================== class VaseManager ==============================
//============================================================================
/** \class VaseManager VaseManager.h
 *	\brief Class managing the vase visuals
 *	\details it creates and updates the vase visuals
 */


class VaseManager: public Manager
{
    public:

        //! Constructor
        VaseManager();

        //! Destructor
        ~VaseManager();

        //! Setup the Vase Manager
        void setup();

        //! Update the Vase Manager
        void update();

        //! Draw the Vase Manager
        void draw();


    private:

        //! Draw all Leds
        void drawLeds();

    private:



};
