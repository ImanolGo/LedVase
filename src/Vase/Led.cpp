/*
 *  Led.h
 *  LED Vase
 *
 *  Created by Imanol Gomez on 05/10/15.
 *
 */


#include "Led.h"


const int Led::SIZE = 4;

Led::Led(const ofPoint& position, int id): BasicVisual(position, SIZE, SIZE), m_id(id)
{
    //Intentionaly left empty
}

Led::~Led()
{
    //Intentionaly left empty
}

void Led::draw()
{
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(m_position);
    ofScale(m_scale.x, m_scale.y);
    ofTranslate(-m_width*0.5,-m_height*0.5);
    
    ofRotateX(m_rotation.x);
    ofRotateY(m_rotation.y);
    
    ofSetColor(m_color);
    ofFill();
    
        ofDrawRectangle(0, 0, m_width, m_height);
    
    ofPopStyle();
    ofPopMatrix();
}


void Led::normalize(const ofRectangle& boundingBox)
{
    m_position.x = (m_position.x - boundingBox.getX()) / boundingBox.getWidth();
    m_position.y = (m_position.y - boundingBox.getY()) / boundingBox.getHeight();
}


void Led::setPixelColor(ofPixelsRef pixels)
{
    m_color = pixels.getColor(m_position.x * pixels.getWidth(), m_position.y * pixels.getHeight());
}

