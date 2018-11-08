#include "hwlib.hpp"

#include "DisplayControl.hpp"

void DisplayControl::Clear(StringType ID){
	switch(ID){
		case RELOAD:{
			reloadOstream << "\f" << hwlib::flush;
			break;
		}
		case HEALTH:{
			healthOstream << "\f" << hwlib::flush;
			break;
		}
		case ENTIRE_SCREEN:{
			reloadOstream << '\f'<< hwlib::flush;
			break;
		}
	}
}

void DisplayControl::DisplayString(const char* s, StringType ID){
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
			reloadOstream << '\f'<< s << hwlib::flush;
			break;
		}
	}
}

void DisplayControl::DisplayString(int s, StringType ID){
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
			reloadOstream << '\f'<< s << hwlib::flush;
			break;
		}
	}
}
