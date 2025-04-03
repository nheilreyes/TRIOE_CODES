#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2
#define BUTTON1 15  // Button for 130°
#define BUTTON2 13  // Button for 180°

void setup() {
  Serial.begin(115200);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("[LoRa 1] LoRa initialization failed!");
    while (1);
  }

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  Serial.println("[LoRa 1] LoRa initialized successfully!");
}

void loop() {
  if (digitalRead(BUTTON1) == LOW) {
    Serial.println("[LoRa 1] Button 1 Pressed! Sending MOVE_130 command...");
    LoRa.beginPacket();
    LoRa.print("MOVE_130");
    LoRa.endPacket();
    delay(500);
  }
  if (digitalRead(BUTTON2) == LOW) {
    Serial.println("[LoRa 1] Button 2 Pressed! Sending MOVE_180 command...");
    LoRa.beginPacket();
    LoRa.print("MOVE_180");
    LoRa.endPacket();
    delay(500);
  }
}