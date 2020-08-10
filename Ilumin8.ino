/*
 * File: Ilumin8.ino
 * Author: Andrew (Edward) Jones 
 * Description: Initial class for ilumin8 program, execution starts here and calls/initializes all other classes.
 * This also contains configuration variables and defines (for input/output pins, lightstrip configuration, etc.)
 * as well as handles calling functions in other classes every refresh period.
 * 
 * TODO: description may need updating in the future
 */

#include <FastLED.h>				// code repository for updating lightstrips, using ver 3.3.3
#include "commandList.h"			// enums for serial commands/options
#include "Lightshows.h"				// seperate namespace for all our lightshow code

// Pin Definitions and variables for optional buttons
#define ON_OFF_TOGGLE_PIN 2			// pin that we're using for our hardware on/off toggle button
bool onOffToggleState, onOffToggle;	// flags for indicating the current position of the toggle button and whether the lights should be on or off

// Definitions for LED Strips
// TODO: update these comments so they aren't garbage before V1 release.
#define LEDS_PER_PIN 300			// the number of LEDS being controlled per pin. We recommend using no more than 300 LEDS per pin, as going higher may cause refresh rate issues.
#define NUM_LED_PINS 2				// constant representing the number of LED pins being used. FastLED supports a maximum of 8 pins, so this value should be between 1 and 8.
#define USED_PORT WS2811_PORTD		// parallel output port we're using. This assigns the following LED pins for output, in order: 25, 26, 27, 28, 14, 15, 29, 11.
// see the readme for info about using other LED chipsets
// TODO: actually write the readme


CRGB leds[LEDS_PER_PIN * NUM_LED_PINS]; // our array of LED color values. 
byte datastreamBuffer[256]; // buffer for storing the datastream that comes in through serial

LSOptions lsOptions; // our instance of the LSOptions struct
Lightshows lightshows(&leds[0], LEDS_PER_PIN * NUM_LED_PINS, LEDS_PER_PIN, &lsOptions); // our instance of the Lightshows class

void setup() // arduino setup function, runs once at startup
{
	// setup optional button pins (should be left here, even if not using)
	pinMode(ON_OFF_TOGGLE_PIN, INPUT_PULLUP);
	onOffToggleState = false;
	onOffToggle = true;

	delay(400);
	// initialize FastLED library
	LEDS.addLeds<USED_PORT, NUM_LED_PINS, GRB>(leds, LEDS_PER_PIN);
	LEDS.clear(true);
	delay(100);
	LEDS.setBrightness(lsOptions.maxBrightness);
	LEDS.show();

	Serial.begin(250000);
	while (!Serial)
	{
		// waits for serial to connect
	}
	leds[0] = CRGB::Green;
	leds[1] = CRGB::Green;
	LEDS.show();
	Serial.flush();
	delay(500);

	lightshows.updateLightshowValues();
	LEDS.show();
}

void loop() // arduino loop function, runs over and over forever
{
	// handle optional input buttons while we're awaiting serial data
	do
	{
		if ((bool)digitalRead(ON_OFF_TOGGLE_PIN) != onOffToggleState)
		{
			onOffToggleState = (bool)digitalRead(ON_OFF_TOGGLE_PIN);
			if(!onOffToggleState)
			{
				onOffToggle = !onOffToggle;
				if (onOffToggle == false)
					LEDS.setBrightness(0);
				else
					LEDS.setBrightness(lsOptions.maxBrightness);
				LEDS.show();
			}
		}
	}
	while(Serial.available() == 0);
	handleDatastream();
	LEDS.show();
	lightshows.updateLightshowValues();
}

void handleDatastream() // manages recieving and processing a datastream
{
	// start with recieving the datastream
	int streamLen = 0;
	while (Serial.available() <= 1)
	{	
		// wait for first 2 bytes
	}
	
	if (Serial.read() == DatastreamStart)
	{
		streamLen = Serial.read();
	}

	
	while (Serial.available() < streamLen)
	{
		// wait for datastream to come in before storing to buffer
	}
	Serial.readBytes(&datastreamBuffer[0], streamLen);


	// datastream is in memory, we can now start processing it
	int index = 0;
	while (index < streamLen && index < 256)
	{
		switch(datastreamBuffer[index])
		{
		/* 
		 * we shouldn't ever process null command characters since we're given how long the stream is
		 * and will exit the while loop after the last byte, but just in case something goes wrong
		 * we set the index to 256, which will always exit the while loop.
		 */
		case NULL:
			index = 256;
			break;
		case DatastreamStart: // TODO: should throw an error since the start of the datastream should be handled seperately
			index++;
			break;
		case ChangeLightshow:
			lightshows.changeLightshow((Shows)datastreamBuffer[index + 1]);
			index += 2;
			break;
		case ChangeOption:
			switch(datastreamBuffer[index + 1])
			{
				case Option_SetBrightness:
					lsOptions.maxBrightness = datastreamBuffer[index + 2];
					if (onOffToggle == true)
						LEDS.setBrightness(lsOptions.maxBrightness);
					index += 3;
					break;
			}
			break;
		case ChangeLightshowOption:
			switch(lightshows.getCurrentLightshow())
			{
			case NULL: // TODO: should throw an error, not a valid state
				index = 256;
				break;
			case SolidColor:
				switch(datastreamBuffer[index + 1])
				{
				case LSOption_SolidColor_Color:
					lsOptions.SolidColor_Color = CRGB(datastreamBuffer[index + 2], datastreamBuffer[index + 3], datastreamBuffer[index + 4]);
					index += 5;
					break;
				}
				break;
			}
			break;
		}
	}
}

