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
#include <ext/hash_map>

CityGMLObject::CityGMLObject(std::string fileName) : osg::Group (*((osg::Group*) osgDB::readNodeFile(fileName))/*, osg::CopyOp::DEEP_COPY_ALL*/) {
	// View needs :
	osg::ref_ptr<osg::MatrixTransform> cityGMLScaleMAT (new osg::MatrixTransform);
	osg::Matrix cityGMLScaleMatrix;
	cityGMLScaleMAT->addChild(((osg::ref_ptr<osg::Node>) this->asGroup()).get());
	cityGMLScaleMAT->setMatrix(cityGMLScaleMatrix);
	myCityGMLScaleMAT = cityGMLScaleMAT;

	// Intializations
	childIndex = 0;
	matIndex = 0;
	//Material Initializations
	mat = new osg::Material;
	mat->setColorMode(osg::Material::AMBIENT); // SPECULAR ou EMISSION ou AMBIENT ou DIFFUSE...
	mat->setAlpha(osg::Material::FRONT_AND_BACK, 0.8);
	// on set les differents types de couleur : (voir cours d'eImage sur lumiere ambiante, diffuse, speculaire, ...)
	mat->setAmbient (osg::Material::FRONT, osg::Vec4(0, 0, 0.3, 0.9));
	mat->setSpecular(osg::Material::FRONT, osg::Vec4(0.1, 0.1, 0.3, 0.9));
	mat->setAmbient (osg::Material::BACK, osg::Vec4(0, 0, 0.1, 1));
	mat->setSpecular(osg::Material::BACK, osg::Vec4(0.2, 0.2, 0.2, 1));

	mat2 = new osg::Material;
	mat2->setColorMode(osg::Material::AMBIENT); // SPECULAR ou EMISSION ou AMBIENT ou DIFFUSE...
	mat2->setAlpha(osg::Material::FRONT_AND_BACK, 0.8);
	// on set les differents types de couleur : (voir cours d'eImage sur lumiere ambiante, diffuse, speculaire, ...)
	mat2->setAmbient (osg::Material::FRONT, osg::Vec4(1, 0, 0.3, 0.9));
	mat2->setSpecular(osg::Material::FRONT, osg::Vec4(1, 0.1, 0.3, 0.9));
	mat2->setAmbient (osg::Material::BACK, osg::Vec4(1, 0, 0.1, 1));
	mat2->setSpecular(osg::Material::BACK, osg::Vec4(1, 0.2, 0.2, 1));
	savedMaterial = mat2;
}

CityGMLObject::~CityGMLObject() {
	// TODO Auto-generated destructor stub
}

// method that has to be called after creating a new CityGMLObject
void CityGMLObject::initializeList() {
	infoList = new hash_map<int, Information>();
}

bool CityGMLObject::displayInfo(Information &info, int qualiOrQuanti, osg::ref_ptr<osg::Group> root) {
	// choix du mode d'affichage et cr�ation de la Geode dans la classe Information :
	DisplayType displayType = OPACITY_CHANGE;
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

void CityGMLObject::changeInfo(){
	if(savedMaterial != NULL){
			removeInfo();
	}
	unsigned int numChildren = this->asGroup()->getNumChildren() -1;
	childIndex = ( childIndex == numChildren ? 0 : childIndex + 1);
	std::cout << "NumChildren vaut " << numChildren << std::endl;
	std::cout << "childIndex vaut " << childIndex << std::endl;
	refreshInfo();
}

void CityGMLObject::setColorInfoBuildings() {
	if(savedMaterial != NULL){
		removeInfo();
	}
	matIndex = 1 - matIndex;
	std::cout << "matIndex vaut " << matIndex << std::endl;
	refreshInfo();
}

void CityGMLObject::refreshInfo() {
	//osg::StateSet* state = this->getOrCreateStateSet();
	//savedMaterial = new osg::Material(*((osg::Material*) state->getAttribute(osg::StateAttribute::MATERIAL)));
	this->asGroup()->getChild(childIndex)->getOrCreateStateSet()->setAttribute((matIndex == 0 ? new osg::Material(*mat2) : new osg::Material(*mat)));

}

void CityGMLObject::removeInfo(){
	//this->asGroup()->getChild(childIndex)->getOrCreateStateSet()->setAttribute(new osg::Material(*savedMaterial));
}


