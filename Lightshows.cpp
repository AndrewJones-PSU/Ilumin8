/*
 * File: Lightshows.h
 * Author: Andrew (Edward) Jones
 * Description: This namespace handles modifying the values of our LED array,
 * as well as getting string representations of lightshow names.
 * 
 * TODO: description may need updating in the future
 */

#include "Lightshows.h"

void Lightshows::lightshowInit(CRGB * leds, int numLEDs, Shows currentLightshow)
{
	switch (currentLightshow)
	{
	case WhiteLights:
		for(int i = 0; i < numLEDs; i++)
		{
			leds[i] = CRGB::White;
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

void Lightshows::updateLightshowValues(CRGB * leds, int numLEDs, Shows currentLightshow)
{
	CRGB temp = CRGB::Black;
	switch (currentLightshow)
	{
	case WhiteLights:
		for(int i = 0; i < numLEDs; i++)
		{
			leds[i] = CRGB::White;
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
			// Serial.println((String)i + "\t" + (String)leds[i].r + "\t" + (String)leds[i].g + "\t" + (String)leds[i].b);
			// Serial.println((String)(i + 1) + "\t" + (String)leds[i + 1].r + "\t" + (String)leds[i + 1].g + "\t" + (String)leds[i + 1].b);
			// Serial.println((String)(i + 2) + "\t" + (String)leds[i + 2].r + "\t" + (String)leds[i + 2].g + "\t" + (String)leds[i + 2].b);
		}
		break;
	}

}