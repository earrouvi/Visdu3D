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

	bool afficher(ModeAffichage, osg::ref_ptr<osg::Group>);

	virtual ~InfoQualitative();
};

#endif /* INFOQUALITATIVE_H_ */
