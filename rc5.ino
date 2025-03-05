#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
  
    Serial.println("Checking RFID module...");
  
    byte version = rfid.PCD_ReadRegister(MFRC522::VersionReg);
    if (version == 0x00 || version == 0xFF) {
        Serial.println("RFID module NOT detected. Check wiring!");
    } else {
        Serial.print("RFID module detected! Version: ");
        Serial.println(version, HEX);
    }
}

void loop() {
}
