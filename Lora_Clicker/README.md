
# **LoRa Clicker**  

The **LoRa Clicker** utilizes an **Arduino Leonardo** and **LoRa modules** to enable the control of a PowerPoint presentation by sending "Next" and "Previous" commands via keyboard input on a computer. 

The **transmitter node** sends movement commands (Next and Prev), which are relayed to the receiver node. The LoRa module is programmed to send *Prev* and *Next* commands. The system relies on **LoRa** for **long-range, low-power communication**.

## **Hardware Required**
- **Arduino Leonardo**
- **Push Buttons**
- **Jumper Wires**
- **Female Headers**  
- **Male Headers** 
- **Universal PCB**  
- **LoRa Module (RA-01)**
- **Resistors**

---

## **Circuit Connections**

The system is divided into **two nodes**: **Transmitter**, and **Receiver Node**, with each node having specific connections.

### **Transmitter Node**  
| Push Button 1 | Arduino Leonardo  |
|---------------|-------------------|
| LEG 1         | GPIO 2            |
| LEG 2         | GND (via resistor) |

| Push Button 2 | Arduino Leonardo  |
|---------------|-------------------|
| LEG 1         | GPIO 4            |
| LEG 2         | GND (via resistor) |

| LoRa Module   | Arduino Leonardo  |
|---------------|-------------------|
| Antenna       | -                 |
| 3.3 V         | 3.3 V             |
| GND           | GND               |
| DIO0          | GPIO 6            |
| RST           | GPIO 5            |
| NSS           | GPIO 3            |
| SCK           | SCK               |
| MOSI          | MOSI              |
| MISO          | MISO              |

### **Receiver  Node**  
| LoRa Module   | Arduino Leonardo  |
|---------------|-------------------|
| Antenna       | -                 |
| 3.3 V         | 3.3 V             |
| GND           | GND               |
| DIO0          | GPIO 3            |
| RST           | GPIO 5            |
| NSS           | GPIO 9            |
| SCK           | SCK               |
| MOSI          | MOSI              |
| MISO          | MISO              |

---

## **Code Explanation**

This LoRa-based system uses an **Arduino Leonardo** and **LoRa modules** to control the presentation slides via keyboard commands, "Next" and "Prev".  

**LoRa** is employed for communication between the transmitter and receiver nodes. It provides **low-power, long-range** data transmission.

---

### **Key Features**
- **Long-range communication** via LoRa
- **Low-power operation** ideal for embedded systems
- **Keyboard input simulation** for controlling PowerPoint slides (Next and Prev commands)
- **Easy to implement** using Arduino Leonardo and LoRa modules

---

### **Schematic**

### **Transmitter Node**
![Untitled design (1)](https://github.com/user-attachments/assets/707fea3b-337b-4a6f-8a4d-cced0b97c123)

### **Receiver Node**
![Untitled design](https://github.com/user-attachments/assets/e1727f32-43ba-48e7-98ac-86ccc1675cdb)

