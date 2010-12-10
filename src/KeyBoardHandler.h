/*
 * KeyBoardHandler.h
 *
 *  Created on: 10 déc. 2010
 *      Author: Flo
 */

#ifndef KEYBOARDHANDLER_H_
#define KEYBOARDHANDLER_H_

// base
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

#include <osg/Material>

// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>
#include <osgGA/GUIEventHandler>

#include <iostream>

class KeyboardEventHandler : public osgGA::GUIEventHandler
{
public:
	KeyboardEventHandler(osg::Material * mat, osg::Material * mat2, osg::StateSet * state);
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter&);
	virtual void accept(osgGA::GUIEventHandlerVisitor& v)   { v.visit(*this); };
	virtual void startAction(int num);

private:
	osg::Material * mat;
	osg::Material * mat2;
	osg::StateSet * state;
};

KeyboardEventHandler::KeyboardEventHandler(osg::Material * mat, osg::Material * mat2, osg::StateSet * state) : GUIEventHandler() {
	this->mat = mat;
	this->mat2 = mat2;
	this->state = state;
}

bool KeyboardEventHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
	switch(ea.getEventType())
	{
	case(osgGA::GUIEventAdapter::KEYDOWN):
        		  {
		switch(ea.getKey())
		{
		case 'w':
			std::cout << " w key pressed" << std::endl;
			return false;
			break;
		case 'z':
			std::cout << " z key pressed" << std::endl;
			startAction(1);
			return true;
			break;
		case 'o':
			std::cout << " o key pressed" << std::endl;
			startAction(2);
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
	if (num == 1) {
		state->setAttribute(mat, osg::StateAttribute::ON);
	} else if (num == 2) {
		state->setAttribute(mat2, osg::StateAttribute::ON);
	}
}


#endif /* KEYBOARDHANDLER_H_ */
