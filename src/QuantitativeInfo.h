/*
 * QuantitativeInfo.h
 *
 *  Created on: 15 déc. 2010
 *      Author: Renard
 */

#ifndef QUANTITATIVEINFO_H_
#define QUANTITATIVEINFO_H_

#include "Information.h"

class QuantitativeInfo : public Information {
public:
	QuantitativeInfo();
	QuantitativeInfo(double d);
	QuantitativeInfo(Information & info);

	virtual bool isQuali() { return false; }
	virtual bool isQuanti() { return true; }

	virtual ~QuantitativeInfo();

	bool display(DisplayMode * displayMode, osg::ref_ptr<osg::Node> node, osg::ref_ptr<osg::Group> root);
};

#endif /* QUANTITATIVEINFO_H_ */
