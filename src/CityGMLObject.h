/*
 * CityGMLObject.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
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
	bool afficherInfos(Information &info, osg::ref_ptr<osg::Group> group);
	void masquerInfos(Information &info, osg::ref_ptr<osg::Group> group);
	osg::ref_ptr<osg::MatrixTransform> getCityGMLScaleMAT() { return myCitygmlScaleMAT; }
	virtual ~CityGMLObject();

private:
	osg::ref_ptr<osg::MatrixTransform> myCitygmlScaleMAT;
};

#endif /* CityGMLObject_H_ */
