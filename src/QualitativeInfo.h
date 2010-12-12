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
	QualitativeInfo(std::string s);
	virtual ~QualitativeInfo();

	bool afficher(DisplayMode * displayMode);

private:
	std::string text;
};

#endif /* QualitativeInfo_H_ */
