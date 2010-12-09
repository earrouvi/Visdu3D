/*
 * ParsedObject.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
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
