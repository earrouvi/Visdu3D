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
#include "ModeAffichage.h"

class Information {
public:

	enum affichages {
		SHAPE_3D,
		COLOR_CHANGE,
		OPACITY_CHANGE
	};

	Information();

	virtual bool afficher(ModeAffichage, osg::ref_ptr<osg::Group>) = 0;

	virtual ~Information();
};

#endif /* INFORMATION_H_ */
