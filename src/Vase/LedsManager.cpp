/*
 *  LedsManager.cpp
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */


#include "ofMain.h"

#include "LedsManager.h"
#include "AppManager.h"


const string LedsManager::LEDS_LIST_PATH = "leds/";
const int LedsManager::NUM_STRIPS = 1;



LedsManager::LedsManager(): Manager()
{
	//Intentionally left empty
}


LedsManager::~LedsManager()
{
    ofLogNotice() <<"LedsManager::Destructor" ;
}


void LedsManager::setup()
{
	if(m_initialized)
		return;


	Manager::setup();
    
    this->setupLeds();
    
    ofLogNotice() <<"LedsManager::initialized" ;
    
}


void LedsManager::setupLeds()
{
    this->readLedsPosition();
    this->normalizeLeds();
}

void LedsManager::readLedsPosition()
{
    int id = 0;
    
    for(int i = 1; i <= NUM_STRIPS; i++)
    {
        string led_section_path = LEDS_LIST_PATH + "leds_" + ofToString(i) + ".txt";
        ofBuffer buffer = ofBufferFromFile(led_section_path);
        
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
            string line = *it;
            
            //ofLogNotice() << line;
            ofPoint ledPosition;
            
            if(parseLedLine(line,ledPosition))
            {
                createLed(ledPosition, id);
                id++;
            }
        }

    }
    
}

void LedsManager::normalizeLeds()
{
    

}



void LedsManager::createLed(const ofPoint& position, int& id)
{
    ofPtr<Led> led = ofPtr<Led> (new Led ( position, id ) );
    led->setColor(ofColor::grey);
    led->setWidth(1);
    m_leds.push_back(led);
    
    ofLogNotice() <<"LedsManager::createLed -> id " << led->getId() << ", x = "  << led->getPosition().x << ", y = "  << led->getPosition().y << ", z = " << led->getPosition().z ;
}

bool LedsManager::parseLedLine(string& line, ofPoint& position)
{
    if(line.size() == 0){
        return false;
    }

    char chars[] = "{}";
    removeCharsFromString(line, chars);
    
    vector <string> strings = ofSplitString(line, ". " );
    
    //id = ofToInt(strings[0]);
    
    vector <string> positionsStrings = ofSplitString(strings[1], ", " );
    
    position.x = ofToFloat(positionsStrings[0])*0.1;
    position.y = ofToFloat(positionsStrings[1])*0.1;
    position.z = ofToFloat(positionsStrings[2])*0.1;
    
    return true;
}

void LedsManager::removeCharsFromString( string &str, char* charsToRemove ) {
    for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
        str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
    }
}

void LedsManager::update()
{
    //
}

void LedsManager::setPixels(ofPixelsRef pixels)
{
    this->setLedColors(pixels);
}

void LedsManager::setLedColors(ofPixelsRef pixels)
{

}


void LedsManager::draw()
{
    for(auto led: m_leds){
        led->draw();
    }
}




