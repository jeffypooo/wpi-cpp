//
// Created by Jefferson Jones on 11/13/17.
//

#include "digital_in.h"

namespace wpi {

    static const char *TAG = "io::DigitalIn";

    /* public */

    DigitalIn::DigitalIn(int pin) : _phys_pin(pin),
                                    _gpio_pin(physPinToGpio(pin)),
                                    _irq_type(InterruptType::NONE),
                                    _irq_handler() {
        pinMode(_gpio_pin, PinMode::MODE_INPUT);
    }

    int DigitalIn::Read() {
        return digitalRead(_gpio_pin);
    }

    void DigitalIn::AttachIRQ(const std::function<void(DigitalIn *)> &handler, InterruptType type) {
        _irq_handler = std::move(handler);
        _irq_type = type;
        wiringPiISR(_gpio_pin, type, reinterpret_cast<void (*)(void)>(&DigitalIn::InternalIRQHandler));
    }

    void DigitalIn::DetachIRQ() {
        _irq_type = InterruptType::NONE;
        _irq_handler = {};
    }

    /* private */

    void DigitalIn::InternalIRQHandler() {
        _irq_handler(this);
    }


}