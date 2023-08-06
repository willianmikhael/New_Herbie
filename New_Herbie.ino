#include "pico/stdlib.h"
#include "dualmotors.h"
#include "defines.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

const uint pin[NUM_SENSORS] = { S1, S2, S3, S4, S5, S6, S7, S8, SENSOR_MAP, SENSOR_STOP };


void setup() {
  Serial.begin(115200);
  sleep_ms(1000);

  float motor_frequency = 980.39f;   // Frequency for motors in Hz
  float turbine_frequency = 500.0f;  // Frequency for turbine in Hz

  float resolucao_do_pwm = 65536.0f;   // PWM resolution (16 bits)
  float frequencia_do_clock = 125e6f;  // Pico clock frequency in Hz

  // Configure the PWM configuration for motors
  pwm_config config = pwm_get_default_config();
  float clkdiv_float = frequencia_do_clock / (motor_frequency * resolucao_do_pwm);
  uint16_t clkdiv = (uint16_t)clkdiv_float;
  pwm_config_set_clkdiv(&config, clkdiv);

  // Configure the PWM configuration for turbine
  pwm_config config_turbine = pwm_get_default_config();
  float clkdiv_float_turbine = frequencia_do_clock / (turbine_frequency * resolucao_do_pwm);
  uint16_t clkdiv_turbine = (uint16_t)clkdiv_float_turbine;
  pwm_config_set_clkdiv(&config_turbine, clkdiv_turbine);

  Serial.print("Frequencia motores: ");
  Serial.println(motor_frequency);
  Serial.print("CLKDIV calculado: ");
  Serial.println(clkdiv);

  Serial.print("Frequencia turbina: ");
  Serial.println(turbine_frequency);
  Serial.print("CLKDIV calculado: ");
  Serial.println(clkdiv_turbine);

  pwm_init(pwm_gpio_to_slice_num(LEFT_MOTOR_PIN_1), &config, true);
  pwm_init(pwm_gpio_to_slice_num(LEFT_MOTOR_PIN_2), &config, true);
  pwm_init(pwm_gpio_to_slice_num(RIGHT_MOTOR_PIN_1), &config, true);
  pwm_init(pwm_gpio_to_slice_num(RIGHT_MOTOR_PIN_2), &config, true);
  pwm_init(pwm_gpio_to_slice_num(TURBINE), &config_turbine, true);

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

  for (int i = 0; i < NUM_SENSORS; i++) {
    gpio_init(pin[i]);
    gpio_set_dir(pin[i], GPIO_IN);
  }

  sleep_ms(1000);
}

void loop() {
  //run();
  readSensors();
  motors(20, 20);
}
