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

//others
#include "ParsedObject.h"
#include "QualitativeInfo.h"

class CityGMLObject : public osg::Group, public ParsedObject {
public:
	CityGMLObject(std::string fileName);

	std::string s;

	void initializeList();
	bool afficherInfos(Information &info);
	void masquerInfos(Information &info);
	osg::ref_ptr<osg::MatrixTransform> getCityGMLScaleMAT() { return myCitygmlScaleMAT; }
	virtual ~CityGMLObject();

private:
	osg::ref_ptr<osg::MatrixTransform> myCitygmlScaleMAT;
};

#endif /* CityGMLObject_H_ */
