#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

int motorPin = 5;     // PWM pin for motor speed
int speedLimit = 255; // Default full speed (0–255 PWM range)

// Predefined RFID tag UIDs for zones
// Replace these with your actual tag values (will guide you later)
byte schoolZone[4] = {0xA3, 0xD4, 0x19, 0x2F};
byte hospitalZone[4] = {0xF9, 0xB2, 0x8C, 0x11};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, speedLimit);

  Serial.println("RFID Speed Control System Initialized...");
}

bool compareTag(byte *tag1, byte *tag2) {
  for (byte i = 0; i < 4; i++) {
    if (tag1[i] != tag2[i]) return false;
  }
  return true;
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("Card UID: ");
  byte *uid = rfid.uid.uidByte;
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(uid[i] < 10 ? "0" : "");
    Serial.print(uid[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Compare with known zone cards
  if (compareTag(uid, schoolZone)) {
    Serial.println("School Zone Detected – Speed Limited to 40%");
    speedLimit = 100;  // (0–255 PWM) → approx 40%
  }
  else if (compareTag(uid, hospitalZone)) {
    Serial.println("Hospital Zone Detected – Speed Limited to 30%");
    speedLimit = 80;  // approx 30%
  }
  else {
    Serial.println("Normal Area – Full Speed");
    speedLimit = 255;
  }

  analogWrite(motorPin, speedLimit);
}
