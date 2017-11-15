//
// Created by Jefferson Jones on 11/13/17.
//

#include "digital_out.h"
#include "io.h"

namespace wpi {

    static const char *TAG = "io::DigitalOut";

    DigitalOut::DigitalOut(int pin) : _phys_pin(pin), _gpio_pin(physPinToGpio(pin)) {
        pinMode(_gpio_pin, PinMode::MODE_OUTPUT);
    }

    int DigitalOut::Read() {
        return digitalRead(_gpio_pin);
    }

    void DigitalOut::Write(int value) {
        int d_value = value > 0 ? 1 : 0;
        digitalWrite(_gpio_pin, d_value);
    }
}
