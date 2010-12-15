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



//others
#include "DisplayMode.h"
#include <vector>

class Information {
public:
	Information();
	~Information();

	virtual bool display(DisplayMode * mode, osg::ref_ptr<osg::Node> node, osg::ref_ptr<osg::Group> root) { printf("Cannot display abstract Information\n"); return false;};

	std::string getMyText() { return myText; }
	void setMyText(std::string s) { myText = s; }

	double getMyFigure() { return myFigure; }
	void setMyFigure(double d) { myFigure = d; }

	int getChildIndex() { return childIndex; }
	void setChildIndex(int i) { childIndex = i; }

	//
	void createSmartiesAndIncatorForNode( osg::ref_ptr<osg::Node> nodeToIndicate);

	//int getChildIndicesSize() { return childIndices->size(); }
	//int getChildIndices(int i) { return childIndices->at(i); }
	//void addIndex(int i) { childIndices->push_back(i); }

private:
	std::string myText;
	double myFigure;
	int childIndex;
	//std::vector<int> * childIndices;
};

#endif /* INFORMATION_H_ */
