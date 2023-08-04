/*

    dualMotors.h

    Autor: Eng. Willian Mikhael da Cunha
    Agosto de 2023
    www.linkedin.com/in/willianmikhael  

*/


#ifndef DUALMOTORS_H
#define DUALMOTORS_H

void motors(int left, int right) {
  if (left >= 0) {
    pwm_set_gpio_level(LEFT_MOTOR_PIN_1, left);
    gpio_put(LEFT_MOTOR_PIN_2, 0);
  } else {
    gpio_put(LEFT_MOTOR_PIN_1, 0);
    pwm_set_gpio_level(LEFT_MOTOR_PIN_2, left);
    left = left * (-1);
  }

  if (right >= 0) {
    pwm_set_gpio_level(RIGHT_MOTOR_PIN_1, right);
    gpio_put(RIGHT_MOTOR_PIN_2, 0);
  } else {
    gpio_put(RIGHT_MOTOR_PIN_1, 0);
    pwm_set_gpio_level(RIGHT_MOTOR_PIN_2, right);
    right = right * (-1);
  }
}

#endif // DUALMOTORS_H
