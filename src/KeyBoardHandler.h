/*
 * KeyBoardHandler.h
 *
 *  Created on: Dec. 2010
 *      Author: Visdu3D, Group project working on cityGML and ESRI formats co-visualization.
 *      Elsa Arrou-Vignod
 *      Florent Buisson
 *      Robin Kervadec
 *      Alice Lan
 *      Michael Lumbroso
 *      Toinon Vigier
 *
 *      This file is given in an OSG tutorial:
 *      http://www.openscenegraph.org/projects/osg/wiki/Support/Tutorials/BasicKeyboardInput
 */

#ifndef KEYBOARDHANDLER_H_
#define KEYBOARDHANDLER_H_

// base
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

#include <osg/Material>

// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/GUIEventHandler>

#include <iostream>
#include "CityGMLObject.h"

class KeyboardEventHandler : public osgGA::GUIEventHandler
{
public:
	KeyboardEventHandler(CityGMLObject * cityGMLObject);
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter&);
	virtual void accept(osgGA::GUIEventHandlerVisitor& v)   { v.visit(*this); };
	virtual void startAction(int num);

private:
	CityGMLObject * refCityGMLObject;
};

KeyboardEventHandler::KeyboardEventHandler(CityGMLObject * cityGMLObject) : GUIEventHandler() {
	this->refCityGMLObject = cityGMLObject;
}

bool KeyboardEventHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
	switch(ea.getEventType())
	{
	case(osgGA::GUIEventAdapter::KEYDOWN):
        			  {
		switch(ea.getKey())
		{
		case 'i':
			std::cout << " i key pressed" << std::endl;
			startAction(1);
			return true;
			break;
		case 'c':
			std::cout << " c key pressed" << std::endl;
			startAction(2);
			return true;
			break;
		case 'o':
			std::cout << " o key pressed" << std::endl;
			return true;
			break;
		default:
			return false;
		}
        			  }
	default:
		return false;
	}
}

void KeyboardEventHandler::startAction(int num) {
	switch(num)
	{
	case 1:
		refCityGMLObject->changeInfo();
		break;
	case 2:
		refCityGMLObject->setColorInfoBuildings();
		break;
	default:
		std::cout << "Changement " << num << "rate" << std::endl;
	}
}


#endif /* KEYBOARDHANDLER_H_ */
