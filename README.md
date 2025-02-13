# 📡 Sistema de Detecção de Som com Raspberry Pi Pico W

Este projeto implementa um sistema de detecção de som utilizando o Raspberry Pi Pico W, um microfone, um buzzer e um display OLED. O objetivo é detectar sons altos e exibir mensagens no display, além de emitir um alerta sonoro.

## 📌 Funcionalidades

- **Detecção de som** via microfone.
- **Exibição de mensagens** em um display OLED SSD1306.
- **Alerta sonoro** com buzzer ao detectar som.
- **Interface modular**, separando código em diferentes arquivos para melhor organização.

### 💻 Linguagem:
- **C** 

### ⚙️ Hardware:
- **Raspberry Pi Pico W**
- **Módulo Microfone** (ADC)
- **Display OLED SSD1306** (I2C)
- **Buzzer**

### 📚 Bibliotecas:
- `pico/stdlib.h` → Controle de GPIO e delays.
- `hardware/adc.h` → Leitura do microfone via ADC.
- `ssd1306.h` → Controle do display OLED SSD1306 via I2C.
- `pwm` → Controle do buzzer.