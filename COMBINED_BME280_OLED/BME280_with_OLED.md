**BME280 with OLED**

This project reads temperature, humidity, and pressure using the BME280 sensor and displays the readings on an OLED screen using the Trioe board.

**Hardware Required:**
	•	Trioe board
	•	Trioe board slice
	•	Jumper wires
	•	OLED screen
	•	Female headers

**Circuit Connection**

The BME280 sensor and the OLED screen communicate via the I2C protocol.

**Code Explanation**

The provided code initializes the BME280 sensor, retrieves temperature, humidity, and pressure readings, and displays them on the OLED screen.

**Key Features:**
	•	Uses WireData for I2C communication
	•	Includes the following libraries:
	•	Adafruit BusIO
	•	Adafruit_GFX.h
	•	Adafruit_SSD1327
	•	Adafruit_BME280
	•	Reads data via I2C communication
	•	Displays sensor details upon initialization
	•	Prints temperature (°C), humidity (%), and pressure (hPa) on the OLED screen along with corresponding icons every second
