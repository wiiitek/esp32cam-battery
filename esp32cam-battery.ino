#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    // waits for serial port to be ready
  }
}

void loop() {}
