//
// Created by Jefferson Jones on 11/13/17.
//

#ifndef RPI_SPI_DIGITALIN_H
#define RPI_SPI_DIGITALIN_H

#include "io.h"
#include <functional>

namespace io {


    class DigitalIn {
    public:
        explicit DigitalIn(int pin);

        virtual ~DigitalIn() = default;

        int Read();

        void AttachIRQ(const std::function<void(DigitalIn *)> &handler, InterruptType type);

        void DetachIRQ();

    private:
        int _phys_pin;
        int _gpio_pin;
        InterruptType _irq_type;
        std::function<void(DigitalIn *)> _irq_handler;

        void (*c_irq_func)();

        void InternalIRQHandler();

    };
}


#endif //RPI_SPI_DIGITALIN_H
