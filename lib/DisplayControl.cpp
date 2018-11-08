#include "hwlib.hpp"

#include "DisplayControl.hpp"

void DisplayControl::ClearNoFlush(StringType ID){
	switch(ID){
		case RELOAD:{
			//reloadDisplay.clear();
			//reloadOstream.goto_xy(0,0);
			reloadOstream << "\r" << "heelo" << hwlib::flush;
			break;
		}
		case HEALTH:{
			//healthDisplay.clear();
			//healthOstream.goto_xy(0,0);
			healthOstream << '\f';
			break;
		}
		case ENTIRE_SCREEN:{
			//display.clear();
			//entireScreenOstream.goto_xy(0,0);
			//entireScreenOstream << "\r" << "heelo" << hwlib::flush;
			break;
		}
	}
}

void DisplayControl::Clear(StringType ID){
	switch(ID){
		case RELOAD:{
			reloadOstream << "\n\f" << hwlib::flush;
			break;
		}
		case HEALTH:{
			healthOstream << "\n\f" << hwlib::flush;
			break;
		}
		case ENTIRE_SCREEN:{
			//entireScreenOstream << '\n\f' << hwlib::flush;
			break;
		}
	}
}

void DisplayControl::DisplayString(const char* s, StringType ID){
	ClearNoFlush(ID); // clear the Ostream, but do not flush yet.
	switch(ID){
		case RELOAD:{
			reloadOstream << '\f'<< s << hwlib::flush;
			break;
		}
		case HEALTH:{
			healthOstream << "\f" << s << hwlib::flush;
			break;
		}
		case ENTIRE_SCREEN:{
			//entireScreenOstream << '\f'<< s << hwlib::flush;
			break;
		}
	}
}

void DisplayControl::DisplayString(int s, StringType ID){
	ClearNoFlush(ID);
	switch(ID){
		case RELOAD:{
			reloadOstream << '\f'<< s << hwlib::flush;
			break;
		}
		case HEALTH:{
			healthOstream << "\f" << s << hwlib::flush;
			break;
		}
		case ENTIRE_SCREEN:{
			//entireScreenOstream << '\f'<< s << hwlib::flush;
			break;
		}
	}
}


/*
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

	void ClearNoFlush();
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
}; */
