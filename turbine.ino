

void readSensors() {
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
}

uint16_t calculate_duty_cycle(uint16_t sensor_value) {
  return (uint16_t)((float)sensor_value / MAX_SENSOR_READING * 65535.0f);
}
