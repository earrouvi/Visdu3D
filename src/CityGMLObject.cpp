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
#include "InfoQualitative.h"
#include <ext/hash_map>

CityGMLObject::CityGMLObject(osg::ref_ptr<osg::Group> groupe) {
	new osg::Group();
	listeInfos = new hash_map<int, Information>();
}

    bool CityGMLObject::afficherInfos(InfoQualitative info, osg::ref_ptr<osg::Group> root) {
	// choix du mode d'affichage et création de la Geode dans la classe Information :
	ModeAffichage * mode = new ModeAffichage();
	bool bienAffiche = info.afficher(mode, root);
	return bienAffiche;
}

void CityGMLObject::masquerInfos(Information info, osg::ref_ptr<osg::Group> root) {
}

CityGMLObject::~CityGMLObject() {
	// TODO Auto-generated destructor stub
}
