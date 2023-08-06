#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include <stdio.h>

#define LEFT_MOTOR_PIN_1 10
#define LEFT_MOTOR_PIN_2 11
#define RIGHT_MOTOR_PIN_1 12
#define RIGHT_MOTOR_PIN_2 9

void setup() {
  Serial.begin(115200);
  sleep_ms(1000);

  float frequencia_desejada = 980.39f;  // Frequência desejada em Hz
  float resolucao_do_pwm = 65536.0f;    // Resolução do PWM (16 bits)
  float frequencia_do_clock = 125e6f;   // Frequência do clock do Pico em Hz

  float clkdiv_float = frequencia_do_clock / (frequencia_desejada * resolucao_do_pwm);
  uint16_t clkdiv = (uint16_t)clkdiv_float;

  Serial.print("Frequencia desejada: ");
  Serial.println(frequencia_desejada);
  Serial.print("CLKDIV calculado: ");
  Serial.println(clkdiv);

  // Configurar o divisor do PWM para definir a frequência
  pwm_config config = pwm_get_default_config();
  pwm_config_set_clkdiv(&config, clkdiv);

  pwm_init(pwm_gpio_to_slice_num(LEFT_MOTOR_PIN_1), &config, true);
  pwm_init(pwm_gpio_to_slice_num(LEFT_MOTOR_PIN_2), &config, true);
  pwm_init(pwm_gpio_to_slice_num(RIGHT_MOTOR_PIN_1), &config, true);
  pwm_init(pwm_gpio_to_slice_num(RIGHT_MOTOR_PIN_2), &config, true);

  gpio_init(LEFT_MOTOR_PIN_1);
  gpio_set_function(LEFT_MOTOR_PIN_1, GPIO_FUNC_PWM);

  gpio_init(LEFT_MOTOR_PIN_2);
  gpio_set_function(LEFT_MOTOR_PIN_2, GPIO_FUNC_PWM);

  gpio_init(RIGHT_MOTOR_PIN_1);
  gpio_set_function(RIGHT_MOTOR_PIN_1, GPIO_FUNC_PWM);

  gpio_init(RIGHT_MOTOR_PIN_2);
  gpio_set_function(RIGHT_MOTOR_PIN_2, GPIO_FUNC_PWM);


  sleep_ms(1000);
}

void loop() {
  motors(20, 20);
}


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