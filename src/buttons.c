#include "../includes/buttons.h"
#include "../includes/pins.h"

void button_pressed(uint8_t *last_btn1, uint8_t *last_btn2) {
    uint8_t btn1 = (PINB & _BV(BUTTON_1)) ? 1 : 0;
    uint8_t btn2 = (PINB & _BV(BUTTON_2)) ? 1 : 0;

    // Debug: Light LED if button pressed
    if (btn1 == 0)
        PORTB |= _BV(LED_1);
    else
        PORTB &= ~_BV(LED_1);

    if (btn2 == 0)
        PORTB |= _BV(LED_2);
    else
        PORTB &= ~_BV(LED_2);

    *last_btn1 = btn1;
    *last_btn2 = btn2;
}
