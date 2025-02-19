# BLE Server

This project sets up an **TRIOE BOARD** as a BLE (Bluetooth Low Energy) server that communicates with a client, receives JSON data, and processes RSSI, message, and temperature values. The built-in LED on pin 2 indicates connection status.

## Hardware Required
- TRIOE board
- USB cable for programming

## Circuit
- The built-in LED (Pin 2) turns **ON** when a BLE client connects and **OFF** when it disconnects.

## Functionality
1. The ESP32-S3 acts as a BLE server with a custom service and characteristic.
2. It advertises its BLE presence, allowing a client to connect.
3. When a client connects, the built-in LED turns **ON**.
4. The client sends JSON data containing RSSI, message, and temperature.
5. The ESP32-S3 parses and prints the received data.
6. When the client disconnects, the LED turns **OFF**, and the ESP32 starts advertising again.

![0001](https://github.com/user-attachments/assets/cdf515e2-0b5b-4e0f-95f6-1f2998c93716)



