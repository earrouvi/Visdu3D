/*
 * QualitativeInfo.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef QUALITATIVEINFO_H_
#define QUALITATIVEINFO_H_

#include "Information.h"

class QualitativeInfo : public Information {
public:
	QualitativeInfo();
	virtual ~QualitativeInfo();

	bool afficher(DisplayMode * displayMode, osg::ref_ptr<osg::Group> group);
};

#endif /* QualitativeInfo_H_ */
