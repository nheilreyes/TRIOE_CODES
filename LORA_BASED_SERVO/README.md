
# **LoRa-Based Servo System**  

This **LoRa-based servo system** utilizes **ESP32** and **LoRa modules** to enable **remote control** of a servo motor. The system operates in two modes: 

1. **Manual triggering** through push buttons.
2. **Automatic scheduling** using a state machine with `millis()`, controlling servo movement between two positions (130° and 180°).

The **transmitter node** sends movement commands (`MOVE_130` or `MOVE_180`), which are relayed to the receiver node. The servo motor is programmed to move between **130° for 2 minutes** and **180° for 30 minutes**, forming a cyclic motion. The system relies on **LoRa** for **long-range, low-power communication**.

## **Hardware Required**
- **ESP32-Wroom-32D**
- **Push Button**
- **Jumper Wires**
- **180° Servo Motor**
- **Female Headers**  
- **Universal PCB**  
- **LoRa Module (RA-01)**
- **Resistor**

---

## **Circuit Connections**

The system is divided into **three nodes**: **Transmitter**, **Relay**, and **Receiver Actuator Node**, with each node having specific connections.

### **Transmitter Node**  
| Push Button 1 | ESP32 Pin  |
|---------------|------------|
| LEG 1         | GPIO 13    |
| LEG 2         | GND (via resistor) |

| Push Button 2 | ESP32 Pin  |
|---------------|------------|
| LEG 1         | GPIO 15    |
| LEG 2         | GND (via resistor) |

| LoRa Module   | ESP32 Pin  |
|---------------|------------|
| Antenna       | -          |
| 3.3 V         | 3.3 V      |
| GND           | GND        |
| DIO0          | GPIO 2     |
| RST           | GPIO 14    |
| NSS           | GPIO 5     |
| SCK           | GPIO 18    |
| MOSI          | GPIO 23    |
| MISO          | GPIO 19    |

### **Relay Node**  
| LoRa Module   | ESP32 Pin  |
|---------------|------------|
| Antenna       | -          |
| 3.3 V         | 3.3 V      |
| GND           | GND        |
| DIO0          | GPIO 2     |
| RST           | GPIO 14    |
| NSS           | GPIO 5     |
| SCK           | GPIO 18    |
| MOSI          | GPIO 23    |
| MISO          | GPIO 19    |

### **Receiver Actuator Node**  
| LoRa Module   | ESP32 Pin  |
|---------------|------------|
| Antenna       | -          |
| 3.3 V         | 3.3 V      |
| GND           | GND        |
| DIO0          | GPIO 2     |
| RST           | GPIO 14    |
| NSS           | GPIO 5     |
| SCK           | GPIO 18    |
| MOSI          | GPIO 23    |
| MISO          | GPIO 19    |

| Servo Motor   | ESP32 Pin  |
|---------------|------------|
| 5 V           | 5 V        |
| GND           | GND        |
| CONTROL       | GPIO 15    |

---

## **Code Explanation**

This LoRa-based servo system is controlled using **ESP32** and **LoRa modules**. It allows **remote control** of the servo motor through:

1. **Manual Triggering:** Push buttons are used to send commands (`MOVE_130` or `MOVE_180`) to move the servo.
2. **Automatic Scheduling:** The servo follows a cyclic schedule:
   - **130° for 2 minutes**.
   - **180° for 30 minutes**.
   
**LoRa** is used for communication between the transmitter and receiver nodes. It provides **low-power, long-range** data transmission.

### **Key Features**

- **Libraries Used:**
  - **`ESP32Servo.h`**: Controls servo movement based on button inputs, enabling precise angle adjustment (130° and 180°).
  - **`SPI.h`**: Facilitates communication between the ESP32 and LoRa module using the SPI protocol, enabling long-distance data transfer.
  - **`LoRa.h`**: Handles wireless communication, sending and receiving movement commands between the nodes.

The servo motor is programmed to move between 130° and 180°, and the state machine ensures that it follows the appropriate cycle, making the system suitable for applications such as **automated access control**.

---

## **Schematic**
### **Transmitter Node**  
![Untitled (1920 x 1080 px) (1)](https://github.com/user-attachments/assets/7acd7364-ab3c-4ed4-b8b9-0fa01b227fe3)

### **Relay Node** 
![Untitled (1920 x 1080 px) (2)](https://github.com/user-attachments/assets/ee1be1e9-3ce3-4a9a-a5ca-5d950f765572)

### **Receiver Actuator Node**  
![Untitled (1920 x 1080 px) (3)](https://github.com/user-attachments/assets/2f9dda87-6c99-45a7-919b-2288edf6a475)
