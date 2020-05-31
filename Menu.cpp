#include "Menu.h"
#include <LiquidCrystal.h>		// code repository for interacting with LCD screen, using ver 1.0.7

Menu::Menu(LiquidCrystal * _lcd, int lcdpinRbl, int lcdpinGbl, int lcdpinBbl)
{
	lcd = _lcd;
	lcdRgbPins[0] = lcdpinRbl;
	lcdRgbPins[1] = lcdpinGbl;
	lcdRgbPins[2] = lcdpinBbl;
	for(int i = 0; i < 2; i++)
	{
		lcdRgbVals[i] = 0;
	}

	uint8_t upArrow[8] = {
		0b00000,
		0b00100,
		0b01010,
		0b10001,
		0b00000,
		0b00000,
		0b00000,
		0b00000
	};
	uint8_t downArrow[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b10001,
		0b01010,
		0b00100,
		0b00000,
		0b00000
	};
	lcd->createChar(1, upArrow);
	lcd->createChar(2, downArrow);
}

void Menu::redraw()
{
	switch (state)
	{
	case MainMenu:
		lcd->setCursor(0, 0);
		lcd->print("=Ilumin8  Main Menu=");
		drawMenu();
		break;
	}
}

// assumed conditions:
// if menuOptions.size() is zero, selectedMenuOption is zero
// selectedMenuOption is a valid index of a String in menuOptions
void Menu::drawMenu()
{	
	if (selectedMenuOption == 0) // first element
	{
		if(menuOptions.size() >= 1)
		{
			lcd->setCursor(0, 1);
			lcd->write(">");
			lcd->print(menuOptions.at(0));
		}
		if(menuOptions.size() >= 2)
		{
			lcd->setCursor(0, 2);
			lcd->write(" ");
			lcd->print(menuOptions.at(1));
		}
		if(menuOptions.size() >= 3)
		{
			lcd->setCursor(0, 3);
			lcd->write(2);
			lcd->print(menuOptions.at(2));
		}
	}
	else if (selectedMenuOption == menuOptions.size() - 1) // last element
	{
		if(menuOptions.size() == 2)
		{
			lcd->setCursor(0, 1);
			lcd->write(" ");
			lcd->print(menuOptions.at(0));
			lcd->setCursor(0, 2);
			lcd->write(">");
			lcd->print(menuOptions.at(1));
		}
		else
		{
			lcd->setCursor(0, 1);
			lcd->write(1);
			lcd->print(menuOptions.at(selectedMenuOption - 2));
			lcd->setCursor(0, 2);
			lcd->write(" ");
			lcd->print(menuOptions.at(selectedMenuOption - 1));
			lcd->setCursor(0, 3);
			lcd->write(">");
			lcd->print(menuOptions.at(selectedMenuOption));
		}
	}
	else
	{
		lcd->setCursor(0, 1);
		lcd->write(1);
		lcd->print(menuOptions.at(selectedMenuOption - 1));
		lcd->setCursor(0, 2);
		lcd->write(">");
		lcd->print(menuOptions.at(selectedMenuOption));
		lcd->setCursor(0, 3);
		lcd->write(2);
		lcd->print(menuOptions.at(selectedMenuOption + 1));
	}
}