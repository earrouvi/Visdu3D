/*
 * Information.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef INFORMATION_H_
#define INFORMATION_H_

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/Group>

//others
#include "DisplayMode.h"



class Information {
public:
	Information();
	~Information();

	bool afficher(DisplayMode * mode) { printf("Cannot display abstract Information"); return false;};

};

#endif /* INFORMATION_H_ */
