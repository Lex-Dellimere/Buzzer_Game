#include "../includes/pins.h"

void init_buzzer(void) {
    // output
    DDRB |= _BV(BUZZER);
    // off
    PORTB &= ~_BV(BUZZER);
}

void init_leds(void) {
    // setup outputs
    DDRB |= _BV(LED_1) | _BV(LED_2);
    // off
    PORTB &= ~(_BV(LED_1) | _BV(LED_2));
}

void init_buttons(void) {
    // Enable internal pull-up resistors
    DDRB |= _BV(BUTTON_1) | _BV(BUTTON_2);

    // Set button pins as inputs
    PORTB &= ~(_BV(BUTTON_1) | _BV(BUTTON_2));
}
