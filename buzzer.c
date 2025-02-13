#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "buzzer.h"
#include <stdio.h>
#include "hardware/gpio.h"

#define BUZZER_PIN 21

#define BUZZER_FREQUENCY 1000
#define BUZZER_DURATION 200  

void buzzer_init() {
    
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    
    pwm_set_wrap(slice_num, 12500);  
    pwm_set_enabled(slice_num, true); 
}

void buzzer_beep() {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(BUZZER_PIN), 6250);
    sleep_ms(BUZZER_DURATION);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(BUZZER_PIN), 0);
}