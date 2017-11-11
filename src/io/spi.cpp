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
#include <thread>
#include <cstring>
#include <utility>
#include "logger.h"
#include "spi.h"

static const char *TAG = "SPI";

namespace io {

    SPI::SPI(SPIChannel channel, int speedHz) : _channel(channel), _speed_hz(speedHz), _fd(-1) {
        double mhz = (double) speedHz / 1000000.0;
        LogV(TAG, "setting up using channel %d at %.2fMHz", channel, mhz);
        this->_fd = wiringPiSPISetup(this->_channel, this->_speed_hz);
        LogV(TAG, "FD = %d", this->_fd);
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
        if (xfer_cnt < 0) {
            LogE(TAG, "transfer of %dB failed.", len);
        } else {
            LogV(TAG, "transfer: %dB", xfer_cnt);
        }
        return xfer_cnt;
    }


}