#include <SPI.h>
#include <MFRC522.h>

// Define RFID module connections
#define SS_PIN 10   // SDA pin on RC522
#define RST_PIN 9   // RST pin on RC522

MFRC522 rfid(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);      // Start serial communication
  SPI.begin();             // Initialize SPI bus
  rfid.PCD_Init();         // Initialize RFID reader
  Serial.println("Place your RFID card/tag near the scanner...");
}

void loop() {
  // Look for new cards
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("RFID Tag UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Halt PICC
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}
