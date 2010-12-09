/*
 * ObjetCityGML.cpp
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "ObjetCityGML.h"
#include "ObjetParse.h"
#include "InfoQualitative.h"
#include <ext/hash_map>

ObjetCityGML::ObjetCityGML(osg::ref_ptr<osg::Group> groupe) {
	new osg::Group();
	listeInfos = new hash_map<int, Information>();
}

    bool ObjetCityGML::afficherInfos(InfoQualitative info, osg::ref_ptr<osg::Group> root) {
	// choix du mode d'affichage et création de la Geode dans la classe Information :
	DisplayMode * mode = new DisplayMode();
	bool bienAffiche = info.afficher(mode, root);
	return bienAffiche;
}

void ObjetCityGML::masquerInfos(Information info, osg::ref_ptr<osg::Group> root) {
}

ObjetCityGML::~ObjetCityGML() {
	// TODO Auto-generated destructor stub
}
