#include <stdio.h>
#include "pico/stdlib.h"
#include "microfone.h"
#include "buzzer.h"
#include "display.h"

int main()
{
    stdio_init_all();
    mic_init();
    buzzer_init();
    display_init();
    bool som_detectado = false; 
    while (true) {
        if (detect_clap()) {
            buzzer_beep();
            display_message("Som Detectado!!"); 
            som_detectado = true;
        }else if (som_detectado) {  
            display_message("Fale algo...");
            som_detectado = false;
        }
        sleep_ms(100);
    }
    return 0;
}
