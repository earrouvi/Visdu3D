/*
 * CityGMLObject.cpp
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "CityGMLObject.h"
#include "ParsedObject.h"
#include "QualitativeInfo.h"
#include <ext/hash_map>

CityGMLObject::CityGMLObject(osg::ref_ptr<osg::Group> groupe) {
	// constructeur qui ne sert à rien
}

<<<<<<< HEAD
// method that has to be called after creating a new CityGMLObject
=======
>>>>>>> f9a64f26a693ce5a4716f22c2e2cf7baa0c53386
void CityGMLObject::initializeList() {
	infoList = new hash_map<int, Information>();
}

bool CityGMLObject::afficherInfos(Information &info, osg::ref_ptr<osg::Group> root) {
	// choix du mode d'affichage et création de la Geode dans la classe Information :
	DisplayMode * mode = new DisplayMode();
	bool bienAffiche = info.afficher(mode, root);
	return bienAffiche;
}

void CityGMLObject::masquerInfos(Information &info, osg::ref_ptr<osg::Group> root) {
}

CityGMLObject::~CityGMLObject() {
	// TODO Auto-generated destructor stub
}
