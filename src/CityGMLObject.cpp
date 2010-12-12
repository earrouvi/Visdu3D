/*
 * CityGMLObject.cpp
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
	myCitygmlNode = citygmlnode;
	myCitygmlScaleMAT = citygmlScaleMAT;
}


// method that has to be called after creating a new CityGMLObject
void CityGMLObject::initializeList() {
	infoList = new hash_map<int, Information>();
}

bool CityGMLObject::displayInfo(Information &info) {
	// choix du mode d'affichage et création de la Geode dans la classe Information :
	DisplayMode * mode = new DisplayMode(DisplayMode::DisplayType);
	bool bienAffiche = info.display(mode, myCitygmlNode);
	return bienAffiche;
}

void CityGMLObject::maskInfo(Information &info) {
}

CityGMLObject::~CityGMLObject() {
	// TODO Auto-generated destructor stub
}
