/*
 * File: Lightshows.h
 * Author: Andrew (Edward) Jones
 * Description: This namespace handles modifying the values of our LED array,
 * as well as getting string representations of lightshow names.
 * 
 * TODO: description may need updating in the future
 */

#ifndef _LIGHTSHOWS_H_
#define _LIGHTSHOWS_H_
#include <FastLED.h> // we need this library for CRGB variable type

enum Shows {Null, WhiteLights, Rainbow, RainbowDrip};

namespace Lightshows
{
	/*
	 * when a new lightshow is selected, this code runs to set up any values that need to be
	 * set prior to running updateLightshowValues.
	 */
	void lightshowInit(CRGB * leds, int numLEDs, Shows currentLightshow);

	/*
	 * updates the leds array for the next output firing. This doesn't output
	 * to the LEDs, it only sets the values of the LEDs in the array, which is used
	 * for outputting.
	 */
	void updateLightshowValues(CRGB * leds, int numLEDs, Shows currentLightshow);
	
}

#endif
