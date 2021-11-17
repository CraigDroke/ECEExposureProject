// The code below is for the UV sensor brick.

//install the below libraries
#include <Adafruit_SI1145.h>
#include <Arduino.h>
#include <U8g2lib.h>

//This defines the dimensions of the display
#ifdef UXU8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef UXU8_HAVE_HW_I2C
#include <Wire.h>
#endif

//may need to define pins for sensor????

U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
Adafruit_SI1145 uv = Adafruit_SI1145();

//This sets up the display and prints headings. It also starts the sensor.
void setup() {
 u8g2.begin();
  u8g2.clearBuffer();
                 
  u8g2.setFont(u8g2_font_ncenB08_tr);   //may need to change the locations these messages are being printed.
  u8g2.drawStr(0,10,"Todays Conditions");
             
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0,10,"UV reading:");

  u8g2.begin();

  uv.begin();
}

//This takes measurements and prints to the display. This should occur every 5 mins.
void loop() {

  float uvv= uv.readUV();
  
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0,10,uvv);
  u8g2.drawStr(0,10,"nM");
  u8g2.sendBuffer();

  delay(10);
