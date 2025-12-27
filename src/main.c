#include "../includes/buttons.h"
#include "../includes/pins.h"
#include <util/delay.h>

int main() {

    init_leds();

    init_buttons();

    uint8_t last_btn1 = 1, last_btn2 = 2;

    while (1) {
        button_pressed(&last_btn1, &last_btn2);
        _delay_ms(10);
    }
}
