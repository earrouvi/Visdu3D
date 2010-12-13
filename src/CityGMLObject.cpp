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
//#include <osg/CopyOp>

//others
#include "CityGMLObject.h"
#include "ParsedObject.h"
#include "QualitativeInfo.h"
#include <ext/hash_map>

CityGMLObject::CityGMLObject(std::string fileName) : osg::Group (*((osg::Group*) osgDB::readNodeFile(fileName))/*, osg::CopyOp::DEEP_COPY_ALL*/) {
	osg::ref_ptr<osg::MatrixTransform> cityGMLScaleMAT (new osg::MatrixTransform);
	osg::Matrix cityGMLScaleMatrix;
	cityGMLScaleMAT->addChild(((osg::ref_ptr<osg::Node>) this->asGroup()).get());
	cityGMLScaleMAT->setMatrix(cityGMLScaleMatrix);
	myCityGMLScaleMAT = cityGMLScaleMAT;
}


// method that has to be called after creating a new CityGMLObject
void CityGMLObject::initializeList() {
	infoList = new hash_map<int, Information>();
}

bool CityGMLObject::displayInfo(Information &info, osg::ref_ptr<osg::Group> root) {
	// choix du mode d'affichage et création de la Geode dans la classe Information :
	DisplayType displayType = TEXT_DISPLAY;
	DisplayMode * mode = new DisplayMode(displayType);

	bool bienAffiche = false;
	//int cast = info.isQuali();
	try {
		bienAffiche = ((QualitativeInfo) info).display(mode, ((osg::ref_ptr<osg::Node>) this->asGroup()), root);
	} catch (char * s) {
		std::cout << "info non qualitative" << std::endl;
	}
	return bienAffiche;
}

void CityGMLObject::maskInfo(Information &info) {
}

CityGMLObject::~CityGMLObject() {
	// TODO Auto-generated destructor stub
}
