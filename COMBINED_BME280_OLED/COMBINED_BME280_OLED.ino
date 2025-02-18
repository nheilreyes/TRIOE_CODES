#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1327.h>
#include <Adafruit_BME280.h>

// OLED Display Configuration on I2C bus 0
#define SDA_OLED 14  
#define SCL_OLED 10
#define SCREEN_ADDRESS 0x3C
TwoWire I2C_OLED = TwoWire(0);  // Use Wire instance 0 for OLED
Adafruit_SSD1327 display(128, 128, &I2C_OLED, -1);

// BME280 Sensor Configuration on I2C bus 1
#define SDA_BME 4
#define SCL_BME 5
#define BME_ADDRESS 0x76
TwoWire I2C_BME = TwoWire(1);  // Use Wire instance 1 for BME280
Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);

  // Initialize I2C for OLED
  I2C_OLED.begin(SDA_OLED, SCL_OLED, 400000); // 400kHz for OLED
  
  // Initialize I2C for BME280
  I2C_BME.begin(SDA_BME, SCL_BME, 400000); // 400kHz for BME280

  // Initialize OLED Display
  if (!display.begin(SCREEN_ADDRESS)) {
    Serial.println("SSD1327 allocation failed.");
    while (1);
  }
  
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("Initializing...");
  display.display();

  // Initialize BME280 on separate bus
  if (!bme.begin(BME_ADDRESS, &I2C_BME)) {
    Serial.println("BME280 not found!");
    display.clearDisplay();
    display.setCursor(0, 20);
    display.println("BME280 Error!");
    display.display();
    while (1);
  }

  Serial.println("BME280 and OLED Initialized Successfully");
}

void loop() {
  sensors_event_t temp_event, pressure_event, humidity_event;
  bme.getTemperatureSensor()->getEvent(&temp_event);
  bme.getPressureSensor()->getEvent(&pressure_event);
  bme.getHumiditySensor()->getEvent(&humidity_event);
  
  Serial.print("Temperature: "); Serial.println(temp_event.temperature);
  Serial.print("Humidity: "); Serial.println(humidity_event.relative_humidity);
  Serial.print("Pressure: "); Serial.println(pressure_event.pressure);
  
  // Display Data on OLED
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("BME280 Data:");
  display.setCursor(0, 30);
  display.print("Temp: "); display.print(temp_event.temperature); display.println(" C");
  display.setCursor(0, 50);
  display.print("Humidity: "); display.print(humidity_event.relative_humidity); display.println(" %");
  display.setCursor(0, 70);
  display.print("Pressure: "); display.print(pressure_event.pressure); display.println(" hPa");
  display.display();

  delay(1000);
}
