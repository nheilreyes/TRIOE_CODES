# **MPU-9250/6500 Sensor**  

This project reads **acceleration, gyroscope, magnetometer, and temperature** data using the **MPU-9250/6500** sensor with a **TRIOE** board.

---

## **Hardware Required**
- **TRIOE Board**
- **MPU-9250/6500 Sensor**
- **Jumper Wires**
- **Female Headers**  

---

## **Circuit Connection**  
The **MPU-9250/6500** sensor uses **I2C communication**. The following connections are required:

| MPU-9250 Pin | TRIOE Pin |
|-------------|-----------|
| VCC         | 3.3V      |
| GND         | GND       |
| SDA         | D4        |
| SCL         | D5        |

---

## **Code Explanation**  
The provided code initializes the **MPU-9250** sensor and retrieves **acceleration, gyroscope, magnetometer, and temperature readings**, displaying them via the **serial monitor**.

### **Key Features:**
- Uses the `MPU9250_WE` library.
- Reads data via **I2C communication**.
- Prints **acceleration (m/s²), gyroscope (°/s), magnetometer (µT), and temperature (°C)** every **500ms**.

## **Schematic**
![Untitled (1920 x 1080 px)](https://github.com/user-attachments/assets/56e48e2a-ecba-4867-a110-b9f80e4a284a)



