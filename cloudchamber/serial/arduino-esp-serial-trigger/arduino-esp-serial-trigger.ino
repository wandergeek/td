#include "analogWrite.h"
#define DAC_PIN_1 26

int brightness = 0;
int step = 1;

void setup() {
  Serial.begin(115200);
  analogWriteResolution(DAC_PIN_1, 10);
}

void loop() {
    while (Serial.available() > 0) {
      byte incomingByte = Serial.read();
      Serial.println("ping");
      analogWrite(DAC_PIN_1, 255);
      delay(1);
      analogWrite(DAC_PIN_1, 0);
  }
}
