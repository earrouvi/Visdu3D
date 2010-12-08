/*
 * ObjetParse.cpp
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "ObjetParse.h"
#include <iostream>
#include <ext/hash_map>
#include "Information.h"

using namespace __gnu_cxx;

ObjetParse::ObjetParse() {
	listeInfos = new hash_map<int, Information>();
}

ObjetParse::~ObjetParse() {
	// TODO Auto-generated destructor stub
}
