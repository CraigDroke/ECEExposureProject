LCD AND UV WORKING TOGETHER:

#include <Arduino.h>
#include <U8g2lib.h>
 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
 
U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // SSD1306 and SSD1308Z are compatible
 

void setup(void) {
  u8g2.begin();
 
}
 void loop()
{
    
 int sensorValue;
    long  sum=0;
    for(int i=0;i<1024;i++)// accumulate readings for 1024 times
    {
        sensorValue=analogRead(A0);
        sum=sensorValue+sum;
        delay(2);
    }
    long meanVal = sum/1024;
    
    
  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_6x12_mr);//u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.setCursor(45,15);       //set cursor
  u8g2.print("UV : ");
  u8g2.setCursor(45,25);
  u8g2.print((meanVal*1000/4.3-83)/(21));
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(1000);  
}

