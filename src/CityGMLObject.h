/*
 * CityGMLObject.h
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

#ifndef CITYGMLOBJECT_H_
#define CITYGMLOBJECT_H_

//osg includes
#include <osg/MatrixTransform>
#include <osg/Material>
#include <osgGA/StateSetManipulator>

//others
#include "ParsedObject.h"
#include "QualitativeInfo.h"
#include "QuantitativeInfo.h"

class CityGMLObject : public osg::Group, public ParsedObject {
public:
	CityGMLObject();
	CityGMLObject(std::string fileName);


	void initializeList();
	bool displayInfo(Information &info, int qualiOrQuanti, osg::ref_ptr<osg::Group> root);
	void maskInfo(Information &info);
	void setDisplayType(DisplayType displayType) { myDisplayType = displayType;}

	void changeInfo();
	void setColorInfoBuildings();
	void refreshInfo();
	void removeInfo();

	osg::ref_ptr<osg::MatrixTransform> getCityGMLScaleMAT() { return myCityGMLScaleMAT; }
	virtual ~CityGMLObject();

private:
	DisplayType myDisplayType;
	osg::ref_ptr<osg::MatrixTransform> myCityGMLScaleMAT;
	unsigned int childIndex;
	int matIndex;
	osg::Material * savedMaterial;
	osg::Material * mat;
	osg::Material * mat2;
};

#endif /* CityGMLObject_H_ */
