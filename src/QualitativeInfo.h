/*
 * QualitativeInfo.h
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

#ifndef QUALITATIVEINFO_H_
#define QUALITATIVEINFO_H_

#include "Information.h"

class QualitativeInfo : public Information {
public:
	QualitativeInfo();
	QualitativeInfo(std::string s);
	QualitativeInfo(Information & info);

	//Permit us to get a pointer on the object with specified type from an Information
	virtual QualitativeInfo * getTypedInfo() { return this; }

	virtual ~QualitativeInfo();

	bool display(DisplayMode * displayMode, osg::ref_ptr<osg::Node> node, osg::ref_ptr<osg::Group> root);

};

#endif /* QualitativeInfo_H_ */
