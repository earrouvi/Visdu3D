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
#include <osgText/Text>
#include <osgText/Font>
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
	switch(mode->getDisplayModeType()){
	// For shape 3D display type SHAPE_3D: we add a 3D shape
	case SHAPE_3D:
	{
		osgText::Text * text = new osgText::Text();
		text->setText(getMyText());
		osg::Vec3 * pos = new osg::Vec3(node->getBound().center());
		text->setPosition(osg::Vec3(pos->x(),pos->y(),node->getBound().radius()*0.25));
		text->setAutoRotateToScreen(true);
		text->setAlignment(osgText::Text::CENTER_CENTER);
		text->setColor(osg::Vec4(1, 0, 0, 1));

		osg::ref_ptr<osg::Box> box (new osg::Box(*pos, node->getBound().radius()*0.25));
		osg::ref_ptr<osg::ShapeDrawable> boxD (new osg::ShapeDrawable(box.get()));
		osg::ref_ptr<osg::Geode> geode (new osg::Geode);

		geode->addDrawable(boxD.get());
		geode->addDrawable(text);
		root->addChild(geode.get());
	}
	break;

	// For color change display type COLOR_CHANGE: we switch color
	case COLOR_CHANGE:
	{
		osg::StateSet* state = node->getOrCreateStateSet();
		state->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
		osg::Material* mat = new osg::Material;
		mat->setColorMode(osg::Material::AMBIENT); // SPECULAR ou EMISSION ou AMBIENT ou DIFFUSE...
		mat->setAlpha(osg::Material::FRONT_AND_BACK, 1);
		// let's set the different lights and colors :
		mat->setAmbient (osg::Material::FRONT, osg::Vec4(1, 0, 0, 1));
		mat->setSpecular(osg::Material::FRONT, osg::Vec4(1, 0, 0, 1));
		mat->setAmbient (osg::Material::BACK, osg::Vec4(0, 0, 1, 1));
		mat->setSpecular(osg::Material::BACK, osg::Vec4(0, 0, 1, 1));
		// now we can apply this material to our object :
		state->setAttributeAndModes(mat, osg::StateAttribute::OVERRIDE);

		osg::ref_ptr<osg::Geode> geode (new osg::Geode);
		//geode->addDrawable(node.get());
		root->addChild(node);
	}
	break;
	// For text display type COLOR_CHANGE: we display the associated text
	case TEXT_DISPLAY:
	{
		osgText::Text * text = new osgText::Text();
		text->setText(getMyText());
		osg::Vec3 * pos = new osg::Vec3(node->getBound().center());
		text->setPosition(osg::Vec3(pos->x(),pos->y(),node->getBound().radius()*0.5));
		text->setAutoRotateToScreen(true);
		text->setAlignment(osgText::Text::CENTER_CENTER);
		text->setColor(osg::Vec4(1, 0, 0, 1));
		osg::ref_ptr<osg::Geode> geode (new osg::Geode);
		geode->addDrawable(text);
		root->addChild(geode.get());
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
