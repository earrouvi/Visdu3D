/*
 * InfoQualitative.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef INFOQUALITATIVE_H_
#define INFOQUALITATIVE_H_

#include "Information.h"

class InfoQualitative : public Information {
public:
	InfoQualitative();
	virtual ~InfoQualitative();

	bool afficher(DisplayMode * modeAffichage, osg::ref_ptr<osg::Group> group);
};

#endif /* INFOQUALITATIVE_H_ */
