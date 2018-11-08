#include "hwlib.hpp"
#include "DisplayControl.hpp"

int main( void ){

   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   hwlib::wait_ms(1000);
   namespace target = hwlib::target;
        auto scl     = hwlib::target::pin_oc(  hwlib::target::pins::scl );
        auto sda     = hwlib::target::pin_oc(  hwlib::target::pins::sda );
        auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
        auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c );
        auto w1 = hwlib::window_part(
            oled,
            hwlib::location( 0, 0 ),
            hwlib::location( 128, 32));
        auto w2 = hwlib::window_part(
            oled,
            hwlib::location( 0, 32 ),
            hwlib::location( 128, 32));
        auto f1 = hwlib::font_default_8x8();
        auto d1 = hwlib::window_ostream( w1, f1 );

        auto f2 = hwlib::font_default_8x8();
        auto d2 = hwlib::window_ostream( w2, f2 );


        auto ose = hwlib::window_part(
            oled, hwlib::location( 0, 0 ),
        hwlib::location( 128, 32));


        DisplayControl dp (oled,w1, w2, d1, d2, 100);
        const char t[] = "est";

        dp.DisplayString(t, StringType::RELOAD);


}
