/*
 * DisplayMode.h
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

#ifndef DISPLAYMODE_H_
#define DISPLAYMODE_H_



class DisplayMode {
public:
	enum DisplayType {
					NONE,
					SHAPE_3D,
					COLOR_CHANGE,
					OPACITY_CHANGE,
					TEXT_DISPLAY
				};
	DisplayMode(DisplayMode::DisplayType dt);
	virtual ~DisplayMode();


	// Gets the type of this DisplayMode
	DisplayType getDisplayModeType(void) {return myDisplayType; }

private:
	DisplayType myDisplayType;
};

#endif /* DISPLAYMODE_H_ */
