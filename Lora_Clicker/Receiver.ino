#include <SPI.h>
#include <LoRa.h>
#include <Keyboard.h>

#define SS 9
#define RST 5
#define DIO0 3

void setup() {
    Serial.begin(9600);
    // while (!Serial);  

    Serial.println("[LoRa Receiver] Initializing...");
    LoRa.setPins(SS, RST, DIO0);

    if (!LoRa.begin(433E6)) {  
        Serial.println("[LoRa Receiver] Initialization failed!");
        while (1);
    }

    Keyboard.begin();
    Serial.println("[LoRa Receiver] Ready to receive commands!");
}

void loop() {
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        String message = "";
        while (LoRa.available()) {
            message += (char)LoRa.read();
        }

        message.trim();
        Serial.print("[LoRa Receiver] Received: ");
        Serial.println(message);

        if (message == "NEXT") {
            Serial.println("[LoRa Receiver] Sending KEY_RIGHT_ARROW...");
            Keyboard.press(KEY_RIGHT_ARROW);
            delay(300);
            Keyboard.release(KEY_RIGHT_ARROW);
        } else if (message == "PREV") {
            Serial.println("[LoRa Receiver] Sending KEY_LEFT_ARROW...");
            Keyboard.press(KEY_LEFT_ARROW);
            delay(300);
            Keyboard.release(KEY_LEFT_ARROW);
        }
    }
}