//
// Created by Jefferson Jones on 11/13/17.
//

#include "digital_out.h"
#include "io.h"

namespace wpi {

    static const char *TAG = "io::DigitalOut";

    DigitalOut::DigitalOut(Pin pin) : pin_(pin) {
        pinMode(pin, PinMode::MODE_OUTPUT);
    }

    int DigitalOut::Read() {
        return digitalRead(pin_);
    }

    void DigitalOut::Write(int value) {
        int d_value = value > 0 ? 1 : 0;
        digitalWrite(pin_, d_value);
    }
}
