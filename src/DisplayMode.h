/*
 * DisplayMode.h
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#ifndef DISPLAYMODE_H_
#define DISPLAYMODE_H_



class DisplayMode {
public:
	DisplayMode();
	virtual ~DisplayMode();

	enum DisplayType {
				NONE,
				SHAPE_3D,
				COLOR_CHANGE,
				OPACITY_CHANGE,
				TEXT_DISPLAY
			};
	// Gets the type of this DisplayMode
	DisplayType getDisplayModeType(void) {return myDisplayType; }

private:
	DisplayType myDisplayType;
};

#endif /* DISPLAYMODE_H_ */
