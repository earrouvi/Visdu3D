/*
 * DisplayMode.h
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

#ifndef DISPLAYMODE_H_
#define DISPLAYMODE_H_

//osg includes
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/Group>
#include <osgText/Text>
#include <osgText/Font>
#include <osg/Material>

#include <iostream>
#include <string.h>

enum DisplayType {
	NO_DISPLAY_TYPE,
	SHAPE_3D,
	COLOR_CHANGE,
	OPACITY_CHANGE,
	TEXT_DISPLAY
};
enum FormType {
	NO_FORM_TYPE,
	CYLINDER,
	SPHERE
};

class DisplayMode {
public:
	DisplayMode(DisplayType dt);
	virtual ~DisplayMode();
	//Setters
	void setText(std::string textToDisplay) { myTextToDisplay = textToDisplay; setDisplayText(true); }
	void setDisplayText(bool onOffDisplayText) { displayText = onOffDisplayText; }
	void setPos(osg::Vec3 pos) { myPos = pos; }
	void setHeight(double height) { myHeight = height; }
	void setRadius(double radius) { myRadius = radius; }

	//Getters
	// Gets the type of this DisplayMode
	DisplayType getDisplayModeType(void) { return myDisplayType; }
	void addGeode(osg::ref_ptr<osg::Group> root, FormType formType);
	osg::Material * getRedMaterial();
	osg::Material * getCoefColorMaterial(int figure);
	osg::Material * getOpacityMaterial();
	osg::Material * getCoefOpacityMaterial(int figure);
	std::string getText() { return myTextToDisplay; }
	osg::Vec3 getPos() { return myPos; }
	double getHeight() { return myHeight; }
	double getRadius() { return myRadius; }


private:
	DisplayType myDisplayType;
	osg::Vec3 myPos;
	double myHeight;
	double myRadius;
	bool displayText;
	std::string myTextToDisplay;
};

#endif /* DISPLAYMODE_H_ */
