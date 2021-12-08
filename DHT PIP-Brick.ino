// The code below is for the temperature and humidity sensor brick.

//install the below libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>

//This defines the dimensions of the display and determines the pin the DHT sensor is connected to.
#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_ADDR   0x3C
#define DHTPIN 2
#define DHTTYPE DHT11

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);
DHT dht(DHTPIN, DHTTYPE);

//This sets up the display and prints headings. It also starts the sensor.
void setup() {
  delay(5000);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();

  display.setCursor(0, 0);
  display.setTextSize(.5);
  display.setTextColor(WHITE);
  display.println("Temp and Humidity:");

  display.display();

  dht.begin();
}

//This takes measurements and prints to the diplay. This should occur every 5 mins.
void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  display.setTextColor(WHITE);
  display.setCursor(0,16);
  display.println(h);
  display.println(t);
  display.setCursor(32,16);
  display.println("%");
  display.setCursor(32,24);
  display.println("C");
  display.display();

  delay(5000);

  display.setTextColor(BLACK);
  display.setCursor(0,16);
  display.println(h);
  display.println(t);
  display.setCursor(32,16);
  display.println("%");
  display.setCursor(32,24);
  display.println("C");
  display.display();
}