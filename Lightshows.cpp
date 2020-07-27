/*
 * File: Lightshows.h
 * Author: Andrew (Edward) Jones
 * Description: This namespace handles modifying the values of our LED array,
 * as well as getting string representations of lightshow names.
 * 
 * TODO: description may need updating in the future
 */

#include "Lightshows.h"

Lightshows::Lightshows(CRGB * _leds, int _numLEDs, int _numLEDsPerPin, LSOptions * _lsOptions)
{
	leds = _leds;
	numLEDs = _numLEDs;
	numLEDsPerPin = _numLEDsPerPin;
	lsOptions = _lsOptions;
	changeLightshow(Shows::RGBTest);
}

Shows Lightshows::getCurrentLightshow()
{
	return currentLightshow;
}

void Lightshows::changeLightshow(Shows newLightshow)
{
	currentLightshow = newLightshow;
	switch (currentLightshow)
	{
	case SolidColor:
		for(int i = 0; i < numLEDs; i++)
		{
			leds[i] = lsOptions->SolidColor_Color;
		}
		break;
	case Rainbow:
		fill_rainbow(leds, numLEDs, 0);
		break;
	case RainbowDrip:
		fill_rainbow(leds, numLEDs, 0);
		for(int i = 0; i < numLEDs; i += (int)(numLEDs / 4))
		{
			leds[i] = CRGB::Black;
		}
		break;
	case RGBTest:
		for(int i = 0; i < numLEDs - 2; i += 3)
		{
			leds[i] = CRGB::Red;
			leds[i + 1] = CRGB::Green;
			leds[i + 2] = CRGB::Blue;
		}
		break;
	}
}

void Lightshows::updateLightshowValues()
{
	CRGB temp = CRGB::Black;
	switch (currentLightshow)
	{
	case SolidColor:
		for(int i = 0; i < numLEDs; i++)
		{
			leds[i] = lsOptions->SolidColor_Color;
		}
		break;
	case Rainbow:
		temp = leds[0];
		for(int i = 0; i < numLEDs - 1; i++)
		{
			leds[i] = leds[i + 1];
		}
		leds[numLEDs - 1] = temp;
		break;
	case RainbowDrip:
		temp = leds[0];
		for(int i = 0; i < numLEDs - 1; i++)
		{
			leds[i] = leds[i + 1];
		}
		leds[numLEDs - 1] = temp;
		break;
	case RGBTest:
		for(int i = 0; i < numLEDs - 2; i += 3)
		{
			leds[i] = CRGB::Red;
			leds[i + 1] = CRGB::Green;
			leds[i + 2] = CRGB::Blue;
		}
		break;
	}

}