/*
 * DisplayMode.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef DISPLAYMODE_H_
#define DISPLAYMODE_H_

enum DisplayType {
			SHAPE_3D,
			COLOR_CHANGE,
			OPACITY_CHANGE
		};

class DisplayMode {
public:
	DisplayMode();
	virtual ~DisplayMode();

	// Gets the type of this DisplayMode
	DisplayType getDisplayModeType(void) {return myDisplayType; }
private:
	DisplayType myDisplayType;
};

#endif /* DISPLAYMODE_H_ */
