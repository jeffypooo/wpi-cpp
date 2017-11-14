//
// Created by Jefferson Jones on 11/13/17.
//
#include "io.h"

namespace io {
    void Setup() {
        wiringPiSetupGpio();
        piHiPri(99);
    }
}