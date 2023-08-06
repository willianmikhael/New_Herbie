/*

    dualMotors.h

    Autor: Eng. Willian Mikhael da Cunha
    Agosto de 2023
    www.linkedin.com/in/willianmikhael  

*/


#ifndef DUALMOTORS_H
#define DUALMOTORS_H

#include "defines.h"
#include "hardware/pwm.h"

void motors(int left, int right) {

  uint16_t left_pwm = (uint16_t)(left * 655.35);
  uint16_t right_pwm = (uint16_t)(right * 655.35);


  if (left_pwm >= 0) {
    pwm_set_gpio_level(LEFT_MOTOR_PIN_1, left_pwm);
    gpio_put(LEFT_MOTOR_PIN_2, 0);
  } else {
    left_pwm = left_pwm * (-1);
    gpio_put(LEFT_MOTOR_PIN_1, 0);
    pwm_set_gpio_level(LEFT_MOTOR_PIN_2, left_pwm);
  }

  if (right_pwm >= 0) {
    pwm_set_gpio_level(RIGHT_MOTOR_PIN_1, right_pwm);
    gpio_put(RIGHT_MOTOR_PIN_2, 0);
  } else {
    right_pwm = right_pwm * (-1);
    gpio_put(RIGHT_MOTOR_PIN_1, 0);
    pwm_set_gpio_level(RIGHT_MOTOR_PIN_2, right_pwm);
  }
}
#endif  // DUALMOTORS_H
