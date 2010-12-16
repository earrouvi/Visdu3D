/*
 * QualitativeInfo.cpp
 *
 *  Created on: Dec. 2010
 *      Author: Visdu3D, Group project working on cityGML and ESRI formats co-visualization.
 *      Elsa Arrou-Vignod
 *      Florent Buisson
 *      Robin Kervadec
 *      Alice Lan
 *      Michael Lumbroso
 *      Toinon Vigier
 */

#include "QualitativeInfo.h"
#include <iostream>

#include <osg/Material>

QualitativeInfo::QualitativeInfo() {
}

QualitativeInfo::QualitativeInfo(std::string s) {
	setMyText(s);
}

QualitativeInfo::QualitativeInfo(Information & info) {
	setMyText(info.getMyText()!="" ? info.getMyText() : "");
}

bool QualitativeInfo::display(DisplayMode * mode, osg::ref_ptr<osg::Node> node, osg::ref_ptr<osg::Group> root) {
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
		//Sets the mode's functionalities
		mode->setText(getMyText());
		mode->setPos(*pos);
		mode->setRadius(radius);
		mode->setHeight(height);
		//Add the 3d object to the scene
		mode->addGeode(root,SPHERE);
	}
	break;
	// For shape 3D display type SHAPE_3D: we add a 3D shape of SMARTIES XD
	case SHAPE_3D_SMARTIES:
	{
		//Sets the mode's functionalities
		mode->setPos(*pos);
		mode->setRadius(radius* 0.5);
		mode->setHeight(height*2.5);
		//Add the 3d object to the scene
		mode->addGeode(root,SMARTIES);

	}
	// For color change display type COLOR_CHANGE: we switch color
	case COLOR_CHANGE:
	{
		//Gets the material from the mode
		osg::Material* mat = new osg::Material(*(mode->getRedMaterial()));
		//Application of the material to the node
		state->setAttributeAndModes(mat, osg::StateAttribute::OVERRIDE);
	}
	break;
	// For text display type TEXT_DISPLAY: we display the associated text
	case TEXT_DISPLAY:
	{
		//Sets the mode's functionalities
		mode->setText(getMyText());
		mode->setRadius(radius);
		mode->setPos(*pos);
		//Add the 3d object to the scene
		mode->addGeode(root,NO_FORM_TYPE);
	}
	// For opacity change display type OPACITY_CHANGE: we switch opacity
	case OPACITY_CHANGE:
	{
		//Gets the material from the mode
		osg::Material* mat = new osg::Material(*(mode->getCoefOpacityMaterial(getMyFigure())));
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

QualitativeInfo::~QualitativeInfo() {
	// TODO Auto-generated destructor stub
}
