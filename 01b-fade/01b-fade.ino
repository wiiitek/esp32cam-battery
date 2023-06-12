// Pin for flash LED
#define FLASH_PIN 4
// Using different ledc channel/timer than camera
#define LEDC_CHANNEL 2
// LEDC base frequency
#define LEDC_BASE_FREQ 10000
// bit precission for LEDC timer
// can be 1-14 bits (1-20 bits for ESP32)
#define LEDC_TIMER_12_BIT 12

// how slow should fading be done
int delayMillis = 10;

// max duty is (2 ^ 12) -1 = 4095
// but we don't want to set it because then the LED is very bright
// we will fade from 0 to 20
int brightnessMin = 0;
int brightnessMax = 20;

int brightness = 0;
int fadeAmount = 1;

void setup() {
  ledcSetup(LEDC_CHANNEL, LEDC_BASE_FREQ, LEDC_TIMER_12_BIT);
  ledcAttachPin(FLASH_PIN, LEDC_CHANNEL);
}

void loop() {
  // set the brightness on LEDC channel 0
  ledcWrite(LEDC_CHANNEL, brightness);
  delay(delayMillis);

  brightness = brightness + fadeAmount;

  if (brightness <= brightnessMin || brightness >= brightnessMax) {
    fadeAmount = -fadeAmount;
  }
}
