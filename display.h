#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>  
#include "inc/ssd1306.h"  


void display_init();
void display_message(char *text);

#endif 
