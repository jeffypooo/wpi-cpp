//
// Created by Jefferson Jones on 11/13/17.
//

#ifndef RPI_SPI_DIGITAL_OUT_H
#define RPI_SPI_DIGITAL_OUT_H

namespace wpi {
    class DigitalOut {
    public:
        explicit DigitalOut(int pin);

        virtual ~DigitalOut() = default;

        int Read();

        void Write(int value);

    private:
        int _phys_pin;
        int _gpio_pin;
    };
}


#endif //RPI_SPI_DIGITAL_OUT_H
