/*
 * QualitativeInfo.cpp
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#include "QualitativeInfo.h"

QualitativeInfo::QualitativeInfo() {
	// TODO Auto-generated constructor stub

}

bool QualitativeInfo::afficher(DisplayMode * mode) {
	switch(mode->getDisplayModeType()){
	// For shape 3D display type SHAPE_3D: we add a 3D shape
	case DisplayMode::SHAPE_3D:
		{
			osg::ref_ptr<osg::Box> boite (new osg::Box(osg::Vec3(10,1,1),1.0f));
			osg::ref_ptr<osg::ShapeDrawable> boiteD (new osg::ShapeDrawable(boite.get()));
			osg::ref_ptr<osg::Geode> geode (new osg::Geode);
			geode->addDrawable(boiteD.get());
			//root->addChild(geode.get());
		}
		break;

	// For shape 3D display type COLOR_CHANGE: we switch color
	case DisplayMode::COLOR_CHANGE:
		{
			osg::ref_ptr<osg::Box> boite (new osg::Box(osg::Vec3(10,1,1),1.0f));
			osg::ref_ptr<osg::ShapeDrawable> boiteD (new osg::ShapeDrawable(boite.get()));
			osg::ref_ptr<osg::Geode> geode (new osg::Geode);
			geode->addDrawable(boiteD.get());
			//root->addChild(geode.get());
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
