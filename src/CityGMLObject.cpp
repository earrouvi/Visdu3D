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

bool CityGMLObject::displayInfo(Information &info, int qualiOrQuanti, osg::ref_ptr<osg::Group> root) {
	// choix du mode d'affichage et création de la Geode dans la classe Information :
	DisplayType displayType = SHAPE_3D;
	DisplayMode * mode = new DisplayMode(displayType);

	bool bienAffiche = false;
	osg::ref_ptr<osg::Group> OSGGroup (new osg::Group(*this->asGroup()));
	osg::ref_ptr<osg::Node> node;

	try {
		node = OSGGroup->getChild(info.getChildIndex());
	} catch (char * s) {
		std::cout << "The group's child you are trying to get probably does not exist." << std::endl;
	}

	if (qualiOrQuanti==0) {
		bienAffiche = static_cast<QualitativeInfo>(info).display(mode, node, root);
	} else if (qualiOrQuanti==1) {
		bienAffiche = static_cast<QuantitativeInfo>(info).display(mode, node, root);
	} else {
		std::cout << "This piece of information is not quantitative." << std::endl;
		std::cout << "Cannot display abstract information." << std::endl;
	}
	return bienAffiche;
}

void CityGMLObject::maskInfo(Information &info) {
}

CityGMLObject::~CityGMLObject() {
	// TODO Auto-generated destructor stub
}
