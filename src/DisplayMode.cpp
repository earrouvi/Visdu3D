/*
 * DisplayMode.cpp
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#include "DisplayMode.h"


DisplayMode::DisplayMode(DisplayType dt)
: myTextToDisplay(""),
  displayText(false)
{
	myDisplayType = dt;
}

DisplayMode::~DisplayMode() {
	// TODO Auto-generated destructor stub
}

void DisplayMode::addGeode(osg::ref_ptr<osg::Group> root){
	//Initializations
	osg::ref_ptr<osg::Geode> myGeode (new osg::Geode());
	osgText::Text * text = new osgText::Text();

	myPos.set(myPos.x(), myPos.y(), myPos.z()+myHeight);

	if(displayText = true && strcmp(myTextToDisplay.c_str(),"")){

		text->setText(myTextToDisplay);

		text->setPosition(osg::Vec3(myPos.x(),myPos.y(),myPos.z()+myHeight/2+text->getCharacterHeight()));
		text->setAutoRotateToScreen(true);
		text->setAlignment(osgText::Text::CENTER_CENTER);
		text->setColor(osg::Vec4(1, 0, 0, 1));
		text->setCharacterSize(root->getBound().radius()*0.15);
	}
	osg::ref_ptr<osg::Sphere> sph (new osg::Sphere(myPos,myRadius * 0.5));
	osg::ref_ptr<osg::ShapeDrawable> sphD (new osg::ShapeDrawable(sph.get()));
	osg::ref_ptr<osg::Geode> geode (new osg::Geode);

	osg::StateSet* state = sphD->getOrCreateStateSet();
	state->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
	osg::Material* mat = new osg::Material;
	mat->setAmbient (osg::Material::FRONT, osg::Vec4(1, 0, 0, 1));
	mat->setSpecular(osg::Material::FRONT, osg::Vec4(0.4, 0, 0, 1));
	mat->setAlpha(osg::Material::FRONT_AND_BACK, 0.6);
	state->setAttributeAndModes((new osg::Material(*mat)), osg::StateAttribute::OVERRIDE);

	geode->addDrawable(sphD.get());
	geode->addDrawable(text);

	root->addChild(geode.get());
}
