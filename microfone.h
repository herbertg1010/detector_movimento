#ifndef MICROFONE_H
#define MICROFONE_H

#include <stdbool.h>

void mic_init();
float mic_read();
bool detect_clap();

#endif