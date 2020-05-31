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
#include "Menu.h"					// Menu class, handles LCD display and inputs

// IMPORTANT: Please read the readme before trying to setup your hardware and pin definitions!

// Definitions for LCD data pins
#define LCDPIN_RS A0				// LCD reset pin
#define LCDPIN_EN A1				// LCD enable pin
#define LCDPIN_D7 53				// LCD data-7 pin
#define LCDPIN_D6 52				// LCD data-6 pin
#define LCDPIN_D5 51				// LCD data-5 pin
#define LCDPIN_D4 50				// LCD data-4 pin

// Definitions for RGB pins for LCD displays with RGB backlights. These must be PWM pins!
#define LCDPIN_RBL 7				// LCD backlight R pin
#define LCDPIN_GBL 6				// LCD backlight G pin
#define LCDPIN_BBL 5				// LCD backlight B pin

// Definitions for button pins
#define BTNPIN_UP 45				// Button Up Pin
#define BTNPIN_DN 46				// Button Down Pin
#define BTNPIN_LT 47				// Button Left Pin
#define BTNPIN_RT 48				// Button Right Pin
#define BTNPIN_SL 49				// Button Select Pin
#define BTNPIN_BK 44				// Button Back Pin


// Definitions for LED Strips
// TODO: update these comments so they aren't garbage before V1 release.
#define LEDS_PER_PIN 300			// the number of LEDS being controlled per pin. We recommend using no more than 300 LEDS per pin, as going higher may cause refresh rate issues.
#define NUM_LED_PINS 1				// constant representing the number of LED pins being used. FastLED supports a maximum of 8 pins, so this value should be between 1 and 8.
#define REFRESH_RATE 80				// how often we update the lightstrip. Changing this value might break some lightshows, so we recommend leaving it at 80.
#define USED_PORT WS2811_PORTD		// parallel output port we're using. This assigns the following LED pins for output, in order: 25, 26, 27, 28, 14, 15, 29, 11.
// see the readme for info about using other LED chipsets. TODO: actually write the readme


void setup() // arduino setup function, runs once at startup
{
	// set our RGB backlight pins to outputs and button inputs to pullups (can't do this in the class, has to be in .ino file)
	pinMode(LCDPIN_RBL, OUTPUT);
	pinMode(LCDPIN_GBL, OUTPUT);
	pinMode(LCDPIN_BBL, OUTPUT);

	pinMode(BTNPIN_UP, INPUT_PULLUP);
	pinMode(BTNPIN_DN, INPUT_PULLUP);
	pinMode(BTNPIN_LT, INPUT_PULLUP);
	pinMode(BTNPIN_RT, INPUT_PULLUP);
	pinMode(BTNPIN_SL, INPUT_PULLUP);
	pinMode(BTNPIN_BK, INPUT_PULLUP);
	
	// initialize menu class, LiquidCrystal has to be declared seperately as declaring within the Menu declaration gives errors.
	LiquidCrystal l(LCDPIN_RS, LCDPIN_EN, LCDPIN_D4, LCDPIN_D5, LCDPIN_D6, LCDPIN_D7);
	Menu m = Menu(&l, LCDPIN_RBL, LCDPIN_GBL, LCDPIN_BBL);

}

void loop() // arduino loop function, runs over and over forever
{
	// TODO:
}
