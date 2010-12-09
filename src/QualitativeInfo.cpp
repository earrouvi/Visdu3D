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

bool QualitativeInfo::afficher(DisplayMode * mode, osg::ref_ptr<osg::Group> root) {
	// pour le type d'affichage : on rajoute une forme 3D
	if (mode == 0) {
		osg::ref_ptr<osg::Box> boite (new osg::Box(osg::Vec3(10,1,1),1.0f));
		osg::ref_ptr<osg::ShapeDrawable> boiteD (new osg::ShapeDrawable(boite.get()));
		osg::ref_ptr<osg::Geode> geode (new osg::Geode);
		geode->addDrawable(boiteD.get());
		root->addChild(geode.get());

	// pour le type d'affichage : on change de couleur
	} else if (mode == 1) {

	}
	return true;
}

QualitativeInfo::~QualitativeInfo() {
	// TODO Auto-generated destructor stub
}
