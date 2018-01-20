//
// Created by Jefferson Jones on 11/13/17.
//

#include "digital_in.h"

namespace wpi {

    static const char *TAG = "io::DigitalIn";

    /* public */

    DigitalIn::DigitalIn(Pin pin) : pin_(pin),
                                    _irq_type(InterruptType::NONE) {
        pinMode(pin_, PinMode::MODE_INPUT);
    }

    int DigitalIn::Read() {
        return digitalRead(pin_);
    }

    void DigitalIn::AttachIRQ(InterruptType type, void (*isr)()) {
        _irq_type = type;
        wiringPiISR(pin_, type, isr);
    }

    void DigitalIn::DetachIRQ() {
        _irq_type = InterruptType::NONE;
        wiringPiISR(pin_, INT_EDGE_SETUP, nullptr);
    }


}