/*
 * ParsedObject.h
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

#ifndef PARSEDOBJECT_H_
#define PARSEDOBJECT_H_

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "ParsedObject.h"
#include <iostream>
#include <ext/hash_map>
#include "Information.h"

using namespace __gnu_cxx;

class ParsedObject {
public:

	hash_map<int, Information> * infoList;

	ParsedObject();
	virtual ~ParsedObject();
};

#endif /* ParsedObject_H_ */
