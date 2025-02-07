#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22   // GPIO do servo
#define LED_PIN 12     // GPIO do LED (BitDogLab)

// Configuração do PWM para a GPIO do servo
void config_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);  
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_wrap(slice_num, 25000);  // Período de 50Hz (20ms)
    pwm_set_enabled(slice_num, true);
}

// Configuração do LED  na GPIO 12
void config_led() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

// Define a posição do servo (500us = 0°, 2400us = 180°)
void set_servo_position(uint slice_num, uint duty_us) {
    uint level = (duty_us * 2500) / 20000; // Ajusta o nível de PWM
    pwm_set_gpio_level(SERVO_PIN, level);
    sleep_ms(5000);  // Aguarda 5 segundos
}

// Movimentação suave entre 0° e 180°
void move_servo_smooth(uint slice_num) {
    while (true) {
        // Movimento de 0° a 180°
        for (uint duty = 500; duty <= 2400; duty += 5) {
            set_servo_position(slice_num, duty);
            gpio_put(LED_PIN, !gpio_get(LED_PIN));  // Alterna LED
            sleep_ms(10);  // Ajusta para suavizar a transição
        }
        // Movimento de 180° a 0°
        for (uint duty = 2400; duty >= 500; duty -= 5) {
            set_servo_position(slice_num, duty);
            gpio_put(LED_PIN, !gpio_get(LED_PIN));  // Alterna LED
            sleep_ms(10);  // Ajusta para suavizar a transição
        }
    }
}

int main() {
    stdio_init_all();
    config_pwm();
    config_led();
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Posições fixas
    set_servo_position(slice_num, 2400);  // 180° (ciclo ativo 2400µs)
    set_servo_position(slice_num, 1470);  // 90° (ciclo ativo 1470µs)
    set_servo_position(slice_num, 500);   // 0° (ciclo ativo 500µs)

    // Movimentação suave do servo entre 0° e 180°
    move_servo_smooth(slice_num);
}
