#include "pico/stdlib.h"
#include "dualmotors.h"
#include "defines.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"


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
  //run();
  motors(200,200);
}
