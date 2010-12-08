/*
 * ObjetCityGML.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef OBJETCITYGML_H_
#define OBJETCITYGML_H_

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "ObjetParse.h"
#include "InfoQualitative.h"

class ObjetCityGML : public osg::Group, public ObjetParse {
public:

	std::string s;

	ObjetCityGML(osg::ref_ptr<osg::Group>);

	void afficherInfos(Information, osg::ref_ptr<osg::Group>);
	void masquerInfos(Information, osg::ref_ptr<osg::Group>);

	virtual ~ObjetCityGML();
};

#endif /* OBJETCITYGML_H_ */
