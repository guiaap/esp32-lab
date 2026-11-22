# Exercise 07: ADC to PWM Conversion
This exercise demonstrates how to control the brightness of an LED using a potentiometer, combining ADC input and PWM output on the ESP32.

The potentiometer's analog reading is mapped to a PWM duty cycle, allowing continuous LED brightness adjustment.

## Components

- ESP32 DevKit V1
- Potentiometer
- LED
- 220 Ω resistor
- Jumper wires
- Breadboard

## Concepts

- Analog-to-Digital Conversion (ADC)
- Pulse Width Modulation (PWM)
- PWM duty cycle
- ADC-to-PWM mapping
- `analogRead()` function
- `map()` function
- `ledcAttach()` and `ledcWrite()` functions