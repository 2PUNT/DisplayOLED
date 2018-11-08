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
	hwlib::window_part& reloadDisplay; // the part of the Display that shows whether the weapon is reloading
	hwlib::window_part& healthDisplay; // the part of the Display that shows the health
	hwlib::window_ostream& reloadOstream; // Ostream to write characters to the reloadScreen
	hwlib::window_ostream& healthOstream; // Ostream to write characters to the reloadScreen

	int health; // variable to store the current health displayed.
public:
	DisplayControl(hwlib::window& _display, hwlib::window_part& reloadDisplay, hwlib::window_part& healthDisplay, hwlib::window_ostream& reloadOstream, hwlib::window_ostream& healthOstream, int _health = -1):
		display(_display),
		reloadDisplay(reloadDisplay),
		healthDisplay(healthDisplay),
		reloadOstream(reloadOstream),
		healthOstream(healthOstream),
		health(_health){
			display.clear();
		}



	///@fn void DisplayControl::clear(const char* s, StringType ID)
	///@brief Clears a screen by id
	///@param ID The screen which should be overriden
	void Clear(StringType ID);


	///@fn void DisplayControl::DisplayString(const char* s, StringType ID)
	///@brief Sets a char string on screen
	///@param s The string to put on screen.
	///@param ID The screen which should be overriden
	void DisplayString(const char* s, StringType ID);

	///@fn void DisplayControl::DisplayString(int s, StringType ID)
	///@brief Sets an int on screen
	///@param s The int to put on screen.
	///@param ID The screen which should be overriden
	void DisplayString(int s, StringType ID);
};

#endif
