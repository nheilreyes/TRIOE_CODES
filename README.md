This code sets up an ESP32-S3 as a Bluetooth Low Energy (BLE) server that communicates with a BLE client, such as another ESP32 or a mobile app. 
The server waits for a client to connect, and when a connection is established, the built-in LED on pin 2 turns ON. 
If the client disconnects, the LED turns OFF, and the ESP32 starts advertising again to allow new connections. 
The server receives JSON-formatted data from the client, which includes values like RSSI (signal strength), a message, and temperature data.
It then extracts and prints this information to the Serial Monitor. 
This setup can be used for wireless data transmission, sensor monitoring, home automation, or other IoT applications where devices need to communicate wirelessly using BLE. 
