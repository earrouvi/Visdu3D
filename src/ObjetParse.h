/*
 * ObjetParse.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef OBJETPARSE_H_
#define OBJETPARSE_H_

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

//others
#include "ObjetParse.h"
#include <iostream>
#include <ext/hash_map>
#include "Information.h"

using namespace __gnu_cxx;

class ObjetParse {
public:

	hash_map<int, Information> * listeInfos;

	ObjetParse();
	virtual ~ObjetParse();
};

#endif /* OBJETPARSE_H_ */
