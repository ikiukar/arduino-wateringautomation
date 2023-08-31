#include <Servo.h>

#define RelayPin 7

int lamasiram = 1000;

void setup() {
    pinMode(RelayPin, OUTPUT);
    delay(5000);
}

void loop() {
    siram();
}

void siram() {
  digitalWrite(RelayPin, HIGH);
  delay(lamasiram);
  digitalWrite(RelayPin, LOW);
  delay(2000);
}
