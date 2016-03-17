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
        
        if(buffer.size())
        {
            while(buffer.isLastLine() == false)
            {
                 string line = buffer.getNextLine();
                 ofPoint ledPosition;
                
                 if(parseLedLine(line,ledPosition))
                 {
                     createLed(ledPosition, id);
                     id++;
                 }
            }
        }

    }
    
}

void LedsManager::normalizeLeds()
{
    float max = 0;
    for (auto led: m_leds)
    {
        auto position = led->getPosition();
        
        if(max < abs(position.x)){
            max = abs(position.x);
        }
        
        if(max < abs(position.y)){
            max = abs(position.y);
        }
        
        if(max < abs(position.z)){
            max = abs(position.z);
        }
        
    }
    
    
    ofLogNotice() <<"LedsManager::normalizeLeds -> max value =  " << max;
    
    bool firstIteration = true;
    
    for (auto led: m_leds)
    {
        auto position = led->getPosition();
        position/=max;
        led->setPosition(position);
        
        ofLogNotice() <<"LedsManager::normalizeLeds -> id " << led->getId() << ", x = "  << led->getPosition().x << ", y = "  << led->getPosition().y << ", z = " << led->getPosition().z ;
        
        if(firstIteration){
            firstIteration = false;
            m_maxPos = position;
            m_minPos = position;
        }
        
        if(m_maxPos.x < position.x){
            m_maxPos.x = position.x;
        }
        
        if(m_maxPos.y < position.y){
            m_maxPos.y = position.y;
        }
        
        if(m_maxPos.z < position.z){
            m_maxPos.z = position.z;
        }
        
        if(m_minPos.x > position.x){
            m_minPos.x = position.x;
        }
        
        if(m_minPos.y > position.y){
            m_minPos.y = position.y;
        }
        
        if(m_minPos.z > position.z){
            m_minPos.z = position.z;
        }
        
    }
    
    ofLogNotice() <<"LedsManager::normalizeLeds -> min position: x = "  << m_minPos.x << ", y = "  << m_minPos.y << ", z = " << m_minPos.z ;
    ofLogNotice() <<"LedsManager::normalizeLeds -> max position: x = "  << m_maxPos.x << ", y = "  << m_maxPos.y << ", z = " << m_maxPos.z ;
}



void LedsManager::createLed(const ofPoint& position, int& id)
{
    int numLeds = 88;
    
    ofPtr<Led> led = ofPtr<Led> (new Led ( position, id ) );
    int color = ofMap(id,0,numLeds-1,0,255);
    led->setColor(color);
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
    
    //vector <string> strings = ofSplitString(line, ". " );
    
    //id = ofToInt(strings[0]);
    
    vector <string> positionsStrings = ofSplitString(line, ", " );
    
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
    
    AppManager::getInstance().getImageManager().update();
}

void LedsManager::setLedColors(ofPixelsRef pixels)
{
    for(auto led: m_leds){
        led->setPixelColor(pixels);
    }
    
}


void LedsManager::draw()
{
    for(auto led: m_leds){
        led->draw();
    }
}




