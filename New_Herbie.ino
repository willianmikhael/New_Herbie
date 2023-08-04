#include "pico/stdlib.h"
#include "dualmotors.h"
#include "defines.h"
#include "hardware/gpio.h"


void setup() {
  gpio_init(SENSOR_MAP);
  gpio_set_dir(SENSOR_MAP, GPIO_IN);

  gpio_init(SENSOR_STOP);
  gpio_set_dir(SENSOR_STOP, GPIO_IN);

  gpio_init(LEFT_MOTOR_PIN_1);
  gpio_init(LEFT_MOTOR_PIN_2);
  gpio_init(RIGHT_MOTOR_PIN_1);
  gpio_init(RIGHT_MOTOR_PIN_2);

  gpio_set_dir(LEFT_MOTOR_PIN_1, GPIO_OUT);
  gpio_set_dir(LEFT_MOTOR_PIN_2, GPIO_OUT);
  gpio_set_dir(RIGHT_MOTOR_PIN_1, GPIO_OUT);
  gpio_set_dir(RIGHT_MOTOR_PIN_2, GPIO_OUT);

  sleep_ms(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
}
