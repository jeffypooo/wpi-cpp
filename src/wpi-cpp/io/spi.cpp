//
// Created by Jefferson Jones on 11/9/17.
//
#ifdef __cplusplus
extern "C" {
#endif

#include <wiringPiSPI.h>

#ifdef __cplusplus
};
#endif

#include <iostream>
#include "spi.h"

static const char *TAG = "SPI";

namespace wpi {

    SPI::SPI(SPIChannel channel, int speedHz) : _channel(channel), _speed_hz(speedHz), _fd(-1) {
        this->_fd = wiringPiSPISetup(this->_channel, this->_speed_hz);
    }

    SPIChannel SPI::GetChannel() {
        return this->_channel;
    }

    int SPI::GetSpeedHz() {
        return this->_speed_hz;
    }

    int SPI::GetFileDesc() {
        return this->_fd;
    }

    bool SPI::IsReady() {
        return this->_fd > 0;
    }

    int SPI::Transfer(uint8_t *buf, int len) {
        int xfer_cnt = 0;
        int tries = 0;
        while (tries++ < 5 && ((xfer_cnt = wiringPiSPIDataRW(this->_channel, buf, len)) < 0));
        return xfer_cnt;
    }


}