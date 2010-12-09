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

//others
#include "DisplayMode.h"



class Information {
public:
	Information();
	~Information();

	virtual bool afficher(DisplayMode * mode, osg::ref_ptr<osg::Group> groupe)=0;

};

#endif /* INFORMATION_H_ */
