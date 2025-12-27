#ifndef PINS_H_
#define PINS_H_

#include "includes.h"

#define TOGGLE_BUZZER() PORTB ^= _BV(BUZZER)

typedef enum {
    BUZZER = PB5,
    LED_1 = PB4,
    LED_2 = PB1,
    BUTTON_1 = PB3,
    BUTTON_2 = PB2
} PINS;

void init_buzzer(void);

void init_leds(void);

void init_buttons(void);

#endif // PINS_H_
