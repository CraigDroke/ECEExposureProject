// The code below is for the UV sensor brick.

//install the below libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SI1145.h>

//This defines the dimensions of the display
#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_ADDR   0x3C
//may need to define pins for sensor????

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);
Adafruit_SI1145 uv = Adafruit_SI1145();

//This sets up the display and prints headings. It also starts the sensor.
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();

  display.setTextSize(.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Today's Conditions");

  display.setTextSize(.5);
  display.setTextColor(WHITE);
  display.println("UV Reading:");

  display.display();

  uv.begin();
}

//This takes measurements and prints to the display. This should occur every 5 mins.
void loop() {

  float uv = dht.readUV();
  
  display.println(uv + "nm");

  delay(10);
  display.clearDisplay();
}