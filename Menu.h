/*
 * File: Menu.h
 * Author: Andrew (Edward) Jones
 * Description: This class handles displaying output to the LCD screen (which almost entirely consists of menus)
 * as well as interpreting inputs sent through the control push-buttons and the serial port. (These are initially
 * sent from the Ilumin8 and SerialHandler classes respectively).
 * 
 * TODO: description may need updating in the future
 */

#ifndef __MENU_H__
#define __MENU_H__

#include <LiquidCrystal.h>		// code repository for interacting with LCD screen, using ver 1.0.7
#include <string.h>
#include <vector>

/* SuperState is an enum that describes different states of the menu in order to help with coding program flow.
 * Here's some general descriptions of what each enum means:
 * -MainMenu: self explanitory
 * -SelectShow: menu allowing selection of the lightshow to display
 * -ShowOptions: menu showing options relevant to the selected lightshow (this may include global settings, for example max brightness)
 * -GlobalOptions: menu showing options relevant to all lightshows as well as Ilumin8 settings
 * -HelpMenu: displays a simple guide on how to navigate the menus
 */
enum SuperState { MainMenu, SelectShow, ShowOptions, GlobalOptions, HelpMenu };

// TODO: make documentation comments more verbose/informative
class Menu
{
private:
	LiquidCrystal * lcd;				// class for managing LCD display output
	int lcdRgbPins[3];					// pin numbers for LCD RGB backlight
	int lcdRgbVals[3];					// RGB values for LCD RGB backlight
	SuperState state;					// current state of the menu (i.e. where we are in the menus)
	int selectedLightshow = 0;			// index of currently active lightshow
	std::vector<String> menuOptions;	// vector of strings of all menu options that are available in the current menu
	int selectedMenuOption = 0;			// index of currently selected menu option

	void redraw();						// redraws the LCD display
	void drawMenu();					// handle drawing menus to the LCD

public:
	Menu(LiquidCrystal * _lcd, int lcdpinRbl, int lcdpinGbl, int lcdpinBbl);	// constructor, initializes everything needed for the class
	void inputLeft();					// handle left button input
	void inputRight();					// handle right button input
	void inputUp();						// handle up button input
	void inputDown();					// handle down button input
	void inputSelect();					// handle select button input
	void inputBack();					// handle back button input
};

#endif