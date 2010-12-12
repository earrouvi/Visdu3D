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
	virtual ~QualitativeInfo();

	bool afficher(DisplayMode * displayMode, osg::ref_ptr<osg::Node> node);

private:
	std::string myText;
};

#endif /* QualitativeInfo_H_ */
