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
#include <vector>

class Information {
public:
	Information();
	~Information();

	bool display(DisplayMode * mode, osg::ref_ptr<osg::Node> node, osg::ref_ptr<osg::Group> root) { printf("Cannot display abstract Information\n"); return false;};

	std::string getMyName() { return myName; }
	void setMyName(std::string s) { myName = s; }

	std::string getMyText() { return myText; }
	void setMyText(std::string s) { myText = s; }

	double getMyFigure() { return myFigure; }
	void setMyFigure(double d) { myFigure = d; }

	int getChildIndex() { return childIndex; }
	void setChildIndex(int i) { childIndex = i; }

	//int getChildIndicesSize() { return childIndices->size(); }
	//int getChildIndices(int i) { return childIndices->at(i); }
	//void addIndex(int i) { childIndices->push_back(i); }

private:
	std::string myName;
	std::string myText;
	double myFigure;
	int childIndex;
	//std::vector<int> * childIndices;
};

#endif /* INFORMATION_H_ */
