//
// Created by Jefferson Jones on 11/13/17.
//
#include "io.h"

namespace wpi {
    void Setup() {
        wiringPiSetupGpio();
        piHiPri(99);
    }
}