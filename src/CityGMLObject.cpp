/*
 * CityGMLObject.cpp
 *
 *  Created on: 8 d�c. 2010
 *      Author: Renard
 */

//osg includes
#include <osgDB/ReadFile>

//others
#include "CityGMLObject.h"
#include "ParsedObject.h"
#include "QualitativeInfo.h"
#include <ext/hash_map>

CityGMLObject::CityGMLObject(std::string fileName) {
	osg::ref_ptr<osg::MatrixTransform> citygmlScaleMAT (new osg::MatrixTransform);
	osg::Matrix citygmlScaleMatrix;
	osg::ref_ptr<osg::Node> citygmlnode (osgDB::readNodeFile(fileName));
	citygmlScaleMAT->addChild(citygmlnode.get());
	citygmlScaleMAT->setMatrix(citygmlScaleMatrix);
	myCitygmlScaleMAT = citygmlScaleMAT;
}


// method that has to be called after creating a new CityGMLObject
void CityGMLObject::initializeList() {
	infoList = new hash_map<int, Information>();
}

bool CityGMLObject::afficherInfos(Information &info) {
	// choix du mode d'affichage et cr�ation de la Geode dans la classe Information :
	DisplayMode * mode = new DisplayMode();
	bool bienAffiche = info.afficher(mode);
	return bienAffiche;
}

void CityGMLObject::masquerInfos(Information &info) {
}

CityGMLObject::~CityGMLObject() {
	// TODO Auto-generated destructor stub
}
