// The code below is for wearable

//install the below libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

//This defines the dimensions of the display
#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);
Adafruit_SI1145 uv = Adafruit_SI1145();

//This sets up the display and prints headings.
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();

  display.setTextSize(.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Today's Conditions");

  display.setTextSize(.5);
  display.setTextColor(WHITE);
  display.println("UV, Temperature and Humidity:");

  display.display();

}

// The loop below should pull from the MQTT server and prints to the display. This should occur every 5 mins.
void loop() {
  
  display.println(uv + "nm");
  display.println(t + "°F");
  display.println(h + "%");

  delay(10);
  display.clearDisplay();
}
