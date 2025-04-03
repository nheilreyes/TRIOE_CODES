#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2

void setup() {
  Serial.begin(115200);  // Ensure this matches other LoRa nodes
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("[LoRa 2] LoRa initialization failed!");
    while (1);
  }

  Serial.println("[LoRa 2] LoRa initialized successfully!");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String message = "";
    
    // Flush bad data
    while (LoRa.available()) {
      char c = (char)LoRa.read();
      if (isPrintable(c)) {
        message += c;
      }
    }

    if (message.length() > 0) {
      Serial.println("[LoRa 2] Received: " + message);
      Serial.println("[LoRa 2] Forwarding to LoRa 3...");

      LoRa.beginPacket();
      LoRa.print(message);
      LoRa.endPacket();
    }
  }
}