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

    void ObjetCityGML::afficherInfos(Information info, osg::ref_ptr<osg::Group> root) {
	// choix du mode d'affichage et création de la Geode dans la classe Information :
	ModeAffichage * mode = new ModeAffichage();
	// je ne sais pas comment me sortir du problème d'héritage
	bool bienAffiche = info.afficher(mode, root);

	//root->addChild(geode.get());
}

void ObjetCityGML::masquerInfos(Information info, osg::ref_ptr<osg::Group> root) {
}

ObjetCityGML::~ObjetCityGML() {
	// TODO Auto-generated destructor stub
}
