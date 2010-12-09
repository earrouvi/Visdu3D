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
	Information();
	~Information();

	enum affichages {
			SHAPE_3D,
			COLOR_CHANGE,
			OPACITY_CHANGE
		};

	//virtual bool afficher(ModeAffichage * mode, osg::ref_ptr<osg::Group> groupe)=0;

};

#endif /* INFORMATION_H_ */
