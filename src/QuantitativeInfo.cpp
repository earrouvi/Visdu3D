/*
 * QuantitativeInfo.cpp
 *
 *  Created on: 15 déc. 2010
 *      Author: Renard
 */

#include "QuantitativeInfo.h"
#include <osgText/Text>
#include <osgText/Font>
#include <iostream>
#include <sstream>

#include <osg/Material>

QuantitativeInfo::QuantitativeInfo() {
	// TODO Auto-generated constructor stub

}

QuantitativeInfo::QuantitativeInfo(double d) {
	setMyFigure(d);
}

QuantitativeInfo::QuantitativeInfo(Information & info) {
	setMyFigure(info.getMyFigure());
}

bool QuantitativeInfo::display(DisplayMode * mode, osg::ref_ptr<osg::Node> node, osg::ref_ptr<osg::Group> root) {
	//Gets or create the stateSet for colour/opacity displays
	osg::StateSet* state = node->getOrCreateStateSet();
	state->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
	//Gets object position and dimentions for the creation of the info
	osg::Vec3 * pos = new osg::Vec3(node->getBound().center());
	double height = node->getBound().radius(); // These are now the same but by applying
	double radius = node->getBound().radius(); // coefs you can change ratios !
	//Creates the display modes
	switch(mode->getDisplayModeType()){
	// For shape 3D display type SHAPE_3D: we add a 3D shape
	case SHAPE_3D:
	{
		//Transform the information figure into a string in order to display it
		std::ostringstream o;
		o << getMyFigure();
		std::string figure = o.str();
		//Sets the mode's functionalities
		mode->setText(figure);
		mode->setPos(*pos);
		mode->setRadius(radius);
		mode->setHeight(height*getMyFigure()/16);// change 4 into another number if the display is not satisfying
		//Add the 3d object to the scene
		mode->addGeode(root,CYLINDER);

	}
	// For shape 3D display type SHAPE_3D: we add a 3D shape of SMARTIES XD
	case SHAPE_3D_SMARTIES:
	{
		//Sets the mode's functionalities
		mode->setPos(*pos);
		mode->setRadius(radius*getMyFigure()* 0.5/40);
		mode->setHeight(height*getMyFigure()*2.5/40);
		//Add the 3d object to the scene
		mode->addGeode(root,SMARTIES);

	}
	// For color change display type COLOR_CHANGE: we switch color
	case COLOR_CHANGE:
	{
		//Gets the material from the mode
		osg::Material* mat = new osg::Material(*(mode->getCoefColorMaterial(getMyFigure())));
		//Application of the material to the node
		state->setAttributeAndModes(mat, osg::StateAttribute::OVERRIDE);
	}
	// For text display type TEXT_DISPLAY: we display the associated text
	case OPACITY_CHANGE:
	{
		//Gets the material from the mode
		osg::Material* mat = new osg::Material(*(mode->getOpacityMaterial()));
		// now we can apply this material to our object :
		state->setAttributeAndModes(mat, osg::StateAttribute::OVERRIDE);
	}
	break;
	default:
		return false;
		break;
	}
	return true;
}


QuantitativeInfo::~QuantitativeInfo() {
	// TODO Auto-generated destructor stub
}
