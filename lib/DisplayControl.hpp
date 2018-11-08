#ifndef DISPLAYCONTROL_HPP
#define DISPLAYCONTROL_HPP

#include "hwlib.hpp"

enum StringType{
	RELOAD,
	HEALTH,
	ENTIRE_SCREEN
};

class DisplayControl{
private:
	hwlib::window& display; // reference to the Display
	hwlib::window_part reloadDisplay; // the part of the Display that shows whether the weapon is reloading
	hwlib::window_part healthDisplay; // the part of the Display that shows the health
	hwlib::window_ostream reloadOstream; // Ostream to write characters to the reloadScreen
	hwlib::window_ostream healthOstream; // Ostream to write characters to the reloadScreen
	hwlib::window_ostream entireScreenOstream; // Ostream to write characters to the Entire screen

	int health; // variable to store the current health displayed.
	
	void ClearNoFlush(StringType ID);
public:
	DisplayControl(hwlib::window& _display, int _health = -1):
		display(_display),
		reloadDisplay(display, hwlib::location(0,0), hwlib::location(display.size.x, display.size.y/2)),
		healthDisplay(display, hwlib::location(display.size.x, display.size.y/2 + 1), hwlib::location(display.size.x, display.size.y - 1)),
		reloadOstream(reloadDisplay, hwlib::font_default_8x8()),
		healthOstream(healthDisplay, hwlib::font_default_8x8()),
		entireScreenOstream(display, hwlib::font_default_8x8()),
		health(_health){
			display.clear();
		//if(health != -1)
		// TODO initialize HealthBar
		}
		
	void Clear(StringType ID);
	void DisplayString(const char* s, StringType ID);
	void DisplayString(int s, StringType ID);
};

#endif
