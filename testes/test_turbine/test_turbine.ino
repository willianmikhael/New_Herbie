#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

#define TURBINE 2

void setup() {

  Serial.begin(115200);
  sleep_ms(1000);

  float turbine_frequency = 500.0f;  // Frequency for turbine in Hz
  float resolucao_do_pwm = 65536.0f;   // PWM resolution (16 bits)
  float frequencia_do_clock = 125e6f;  // Pico clock frequency in Hz

  // Configure the PWM configuration for turbine
  pwm_config config_turbine = pwm_get_default_config();
  float clkdiv_float_turbine = frequencia_do_clock / (turbine_frequency * resolucao_do_pwm);
  uint16_t clkdiv_turbine = (uint16_t)clkdiv_float_turbine;
  pwm_config_set_clkdiv(&config_turbine, clkdiv_turbine);

  Serial.print("Frequencia turbina: ");
  Serial.println(turbine_frequency);
  Serial.print("CLKDIV calculado: ");
  Serial.println(clkdiv_turbine);

  pwm_init(pwm_gpio_to_slice_num(TURBINE), &config_turbine, true);
  gpio_init(TURBINE);
  gpio_set_function(TURBINE, GPIO_FUNC_PWM);
}

void loop() {
  turbine(50);
}


void turbine(int value) {
  uint16_t throttle = (uint16_t)(value * 655.35);
  pwm_set_gpio_level(TURBINE, throttle);
}
