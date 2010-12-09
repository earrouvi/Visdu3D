/*
 * CityGMLObject.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef CITYGMLOBJECT_H_
#define CITYGMLOBJECT_H_

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "ParsedObject.h"
#include "QualitativeInfo.h"

class CityGMLObject : public osg::Group, public ParsedObject {
public:
	CityGMLObject(osg::ref_ptr<osg::Group>);
	std::string s;



	bool afficherInfos(Information &info, osg::ref_ptr<osg::Group> group);
	void masquerInfos(Information &info, osg::ref_ptr<osg::Group> group);

	virtual ~CityGMLObject();
};

#endif /* CityGMLObject_H_ */
