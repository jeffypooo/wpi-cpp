//
// Created by Jefferson Jones on 11/13/17.
//

#ifndef RPI_SPI_PINS_H
#define RPI_SPI_PINS_H

#ifdef __cplusplus
extern "C" {
#endif
#include <wiringPi.h>
#ifdef __cplusplus
};
#endif

namespace wpi {

    void Setup();

    enum Pin : int {
        P0 = 0, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16
    };

    enum PinMode : int {
        MODE_INPUT = INPUT,
        MODE_OUTPUT = OUTPUT,
        MODE_PWM = PWM_OUTPUT
    };

    enum InterruptType : int {
        NONE = -1,
        FALLING_EDGE = INT_EDGE_FALLING,
        RISING_EDGE = INT_EDGE_RISING,
        BOTH = INT_EDGE_BOTH
    };
}
#endif //RPI_SPI_PINS_H
