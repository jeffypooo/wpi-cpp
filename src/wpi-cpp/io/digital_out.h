//
// Created by Jefferson Jones on 11/13/17.
//

#ifndef RPI_SPI_DIGITAL_OUT_H
#define RPI_SPI_DIGITAL_OUT_H

#include "io.h"

namespace wpi {
    class DigitalOut {
    public:
        explicit DigitalOut(Pin pin);

        virtual ~DigitalOut() = default;

        int Read();

        void Write(int value);

    private:
        Pin pin_;
    };
}


#endif //RPI_SPI_DIGITAL_OUT_H
