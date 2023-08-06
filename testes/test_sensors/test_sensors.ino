#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include <stdlib.h>

#define NUM_SENSORS 10
#define THRESHOLD 5000
#define MAX_SENSOR_READING 1023

#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define S7 7
#define S8 8
#define S9 9
#define S10 10

// Define the GPIO pins for the sensors
const uint pin[NUM_SENSORS] = { S1, S2, S3, S4, S5, S6, S7, S8, S9, S10 };

void setup() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    gpio_init(pin[i]);
    gpio_set_dir(pin[i], GPIO_IN);
  }

  sleep_ms(1000);
}

void loop() {
  uint16_t sensor_value[NUM_SENSORS];

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensor_value[i] = gpio_get(pin[i]);
  }

  uint16_t duty_cycle[NUM_SENSORS];

  // Calculate duty cycles
  for (int i = 0; i < NUM_SENSORS; i++) {
    duty_cycle[i] = calculate_duty_cycle(sensor_value[i]);
  }

  // Set PWM duty cycles
  for (int i = 0; i < NUM_SENSORS; i++) {
    pwm_set_gpio_level(pin[i], duty_cycle[i]);
  }

  bool data[NUM_SENSORS];

  // Check threshold
  for (int i = 0; i < NUM_SENSORS; i++) {
    data[i] = duty_cycle[i] > THRESHOLD;
  }

  // Print sensor values and threshold
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(i);
    Serial.print(": ");
    Serial.println(duty_cycle[i]);
  }

  sleep_ms(100);
}

uint16_t calculate_duty_cycle(uint16_t sensor_value) {
  return (uint16_t)((float)sensor_value / MAX_SENSOR_READING * 65535.0f);
}
