#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1327.h>

#define SDA_PIN 14  // Change to 21 if needed
#define SCL_PIN 10 // Change to 22 if needed
#define SCREEN_ADDRESS 0x3C  // Use the address from the scanner

Adafruit_SSD1327 display(128, 128, &Wire, -1);

void setup() {
  Serial.begin(9600);
  Wire.begin(SDA_PIN, SCL_PIN);
  
  if (!display.begin(SCREEN_ADDRESS)) {
    Serial.println("SSD1327 allocation failed. Check wiring and address.");
    while (1);
  }

  Serial.println("SSD1327 initialized successfully");

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1327_WHITE);
  display.setCursor(0, 10);
  display.println("Hello, world!");
  display.display();
}

void loop() {}
