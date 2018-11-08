#include "hwlib.hpp"

#include "DisplayControl.hpp"

int main(void){
	// kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(500);
	
	auto scl     = hwlib::target::pin_oc(  hwlib::target::pins::d12 );
	auto sda     = hwlib::target::pin_oc(  hwlib::target::pins::d11 );
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
	auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c );

	
	DisplayControl displayControl = DisplayControl(oled);
	
	hwlib::window_part testWin = hwlib::window_part(oled, hwlib::location(0,0), hwlib::location(oled.size.x, oled.size.y/2));
	hwlib::window_ostream testOstream = hwlib::window_ostream(testWin, hwlib::font_default_8x8());
	testOstream << "\f" << "EIN STRINGHUGSAUGHIUAGD" << hwlib::flush;
	
	while(true){
		hwlib::cout <<"Loop start\n";
		displayControl.DisplayString("Displaying supper cool string!\0\n", StringType::RELOAD);
		displayControl.DisplayString(1234, StringType::HEALTH);
		hwlib::cout <<"first write complete\n";
		hwlib::wait_ms(1000);
		displayControl.Clear(StringType::RELOAD);
		displayControl.Clear(StringType::HEALTH);
		displayControl.DisplayString("This is a very long string, so long i need the entire display to show it... maybe...", StringType::ENTIRE_SCREEN);
		hwlib::cout <<"Second write complete\n";
		hwlib::wait_ms(1000);
		displayControl.Clear(StringType::ENTIRE_SCREEN);
	}
	
}
