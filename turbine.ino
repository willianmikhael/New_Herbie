  void pwm_write_us(uint16_t us) {
    pwm_set_gpio_level(TURBINE, us);
  }

  void turbine(int value) {
    int throttle = map(value, 0, 100, 1000, 2000);
    pwm_write_us(throttle);
  }
  