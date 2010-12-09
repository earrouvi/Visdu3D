/*
 * ParsedObject.cpp
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "ParsedObject.h"
#include <iostream>
#include <ext/hash_map>
#include "Information.h"

using namespace __gnu_cxx;

ParsedObject::ParsedObject() {
	infoList = new hash_map<int, Information>();
}

ParsedObject::~ParsedObject() {
	// TODO Auto-generated destructor stub
}
