/*
 * File: Lightshows.h
 * Author: Andrew (Edward) Jones
 * Description: This class handles modifying the values of our LED array,
 * as well as holding values (or pointers to values) from our .ino file
 * 
 * TODO: description may need updating in the future
 */

#ifndef _LIGHTSHOWS_H_
#define _LIGHTSHOWS_H_
#include <FastLED.h> // we need this library for CRGB variable type

enum Shows {Null, WhiteLights, Rainbow, RainbowDrip, RGBTest}; // enum of all our lightshows

// struct that stores all our options for lightshows
struct LSOptions{
	uint8_t maxBrightness = 40;
};

class Lightshows
{
private:
	CRGB * leds; // pointer to our array of LEDs (stored in ilumin8.ino)
	int numLEDs; // total number of LEDs
	int numLEDsPerPin; // number of LEDs per channel/pin
	LSOptions * lsOptions; // pointer to our options structure (stored in ilumin8.ino)
	Shows currentLightshow; // currently selected lightshow
public:
	Lightshows(CRGB * leds, int numLEDs, int numLEDsPerPin, LSOptions * lsOptions); // initialize the Lightshows class with necessary values and pointers

	void changeLightshow(Shows newLightshow); // change our currently selected lightshow. Updates all necessary values in the process.
	void updateLightshowValues(); // changes our array of LED values in preparation for the next write call.
};

#endif
