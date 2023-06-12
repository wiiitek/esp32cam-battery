#define FLASH_PIN 4

void setup() {
  // initialize FLASH_PIN as an output.
  pinMode(FLASH_PIN, OUTPUT);
}

void loop() {
  digitalWrite(FLASH_PIN, HIGH);
  delay(10);
  digitalWrite(FLASH_PIN, LOW);
  delay(990);
}
