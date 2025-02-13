#include <stdio.h>
#include "microfone.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

#define MIC_CHANNEL 2
#define MIC_PIN (26 + MIC_CHANNEL)

#define MIC_THRESHOLD 0.6f  
#define MIN_PEAKS 3 
#define ADC_ADJUST(x) (x * 3.3f / (1 << 12u) - 1.65f)
#define ADC_CLOCK_DIV 96.f
#define SAMPLE_COUNT 50  
#define SMOOTHING_FACTOR 0.2f 

void mic_init() {
    adc_gpio_init(MIC_PIN);
    adc_init();
    adc_select_input(MIC_CHANNEL);
    adc_set_clkdiv(ADC_CLOCK_DIV);
}

float mic_read() {
    static float smoothed_value = 0;
    float raw_value = ADC_ADJUST(adc_read());
    smoothed_value = (SMOOTHING_FACTOR * raw_value) + ((1 - SMOOTHING_FACTOR) * smoothed_value);
    return smoothed_value;
}

bool detect_clap() {
    int peak_count = 0;
    float last_value = mic_read();
    
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        float current_value = mic_read();

        if (current_value - last_value > MIC_THRESHOLD) {  
            peak_count++;
        }

        last_value = current_value;
        sleep_us(300); 
    }

    return peak_count >= MIN_PEAKS;
}