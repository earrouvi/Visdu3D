/*
 * Information.h
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

	bool display(DisplayMode * mode, osg::ref_ptr<osg::Node> node, osg::ref_ptr<osg::Group> root) { printf("Cannot display abstract Information\n"); return false;};
	std::string getMyText() { return myText; }
	void setMyText(std::string s) { myText = s; }

	//bool isQuali() { return false; }

private:
	std::string myText;
};

#endif /* INFORMATION_H_ */
