//
// Created by Jefferson Jones on 11/13/17.
//

#ifndef RPI_SPI_DIGITALIN_H
#define RPI_SPI_DIGITALIN_H

#include "io.h"
#include <functional>

namespace wpi {


    class DigitalIn {
    public:
        explicit DigitalIn(Pin pin);

        virtual ~DigitalIn() = default;

        int Read();

        void AttachIRQ(InterruptType type, void (*isr)());

        void DetachIRQ();

    private:
        int pin_;
        InterruptType _irq_type;

    };
}


#endif //RPI_SPI_DIGITALIN_H
