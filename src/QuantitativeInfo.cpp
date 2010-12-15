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
	switch(mode->getDisplayModeType()){
	// For shape 3D display type SHAPE_3D: we add a 3D shape
	case SHAPE_3D:
	{
		osgText::Text * text = new osgText::Text();
		std::ostringstream o;
		o << getMyFigure();
		std::string figure = o.str();
		text->setText(figure);

		osg::Vec3 * pos = new osg::Vec3(node->getBound().center());
		double height = node->getBound().radius()*getMyFigure()/4; // change 4 into another number if the display is not satisfying
		pos->set(pos->x(), pos->y(), pos->z()+height/2);
		text->setPosition(osg::Vec3(pos->x(),pos->y(),pos->z()+height/2+text->getCharacterHeight()));
		text->setAutoRotateToScreen(true);
		text->setAlignment(osgText::Text::CENTER_CENTER);
		text->setColor(osg::Vec4(1, 0, 0, 1));
		text->setCharacterSize(root->getBound().radius()*0.15);

		osg::ref_ptr<osg::Cylinder> cyl (new osg::Cylinder(*pos, node->getBound().radius()*0.5, height));
		osg::ref_ptr<osg::ShapeDrawable> cylD (new osg::ShapeDrawable(cyl.get()));
		osg::ref_ptr<osg::Geode> geode (new osg::Geode);

		osg::StateSet* state = cylD->getOrCreateStateSet();
		state->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
		osg::Material* mat = new osg::Material;
		mat->setAmbient (osg::Material::FRONT, osg::Vec4(1, 0, 0, 1));
		mat->setSpecular(osg::Material::FRONT, osg::Vec4(0.4, 0, 0, 1));
		mat->setAlpha(osg::Material::FRONT_AND_BACK, 0.6);
		state->setAttributeAndModes((new osg::Material(*mat)), osg::StateAttribute::OVERRIDE);

		geode->addDrawable(cylD.get());
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


QuantitativeInfo::~QuantitativeInfo() {
	// TODO Auto-generated destructor stub
}
