#include "pico/stdlib.h"
#include "dualmotors.h"
#include "defines.h"
#include "hardware/gpio.h"


void setup() {
  Serial.begin(9600);
  serial1.begin(9600);

  gpio_init(SENSOR_MAP);
  gpio_set_dir(SENSOR_MAP, GPIO_IN);

  gpio_init(SENSOR_STOP);
  gpio_set_dir(SENSOR_STOP, GPIO_IN);

  gpio_init(LEFT_MOTOR_PIN_1);
  gpio_set_function(LEFT_MOTOR_PIN_1, GPIO_FUNC_PWM);

  gpio_init(LEFT_MOTOR_PIN_2);
  gpio_set_function(LEFT_MOTOR_PIN_2, GPIO_FUNC_PWM);

  gpio_init(RIGHT_MOTOR_PIN_1);
  gpio_set_function(RIGHT_MOTOR_PIN_1, GPIO_FUNC_PWM);

  gpio_init(RIGHT_MOTOR_PIN_2);
  gpio_set_function(RIGHT_MOTOR_PIN_2, GPIO_FUNC_PWM);

  gpio_init(TURBINE);
  gpio_set_function(TURBINE, GPIO_FUNC_PWM);

  sleep_ms(1000);
}

void loop() { 
  processMapValue(map,5);
  //run();
}
