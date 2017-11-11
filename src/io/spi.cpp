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

    void SPI::Start() {
        if (this->_reader_thr != nullptr) return;
        LogV(TAG, "starting reader thread");
        this->_stopped = false;
        this->_reader_thr = new std::thread(&SPI::ReaderThreadLoop, this);
    }

    void SPI::Stop() {
        if (this->_data_cb == nullptr) return;
        this->_stopped = true;
        this->_reader_thr = nullptr;
    }

    void SPI::Write(uint8_t *data, int len) {
        //TODO: implement
        LogE(TAG, "Write is not implemented");
    }

    void SPI::SetDataHandler(std::function<void(std::vector<uint8_t>)> func) {
        this->_data_cb = std::move(func);
    }

    void SPI::ReaderThreadLoop() {
        auto *buf = new uint8_t[32];
        while (!this->_stopped) {
            int read = wiringPiSPIDataRW(this->_channel, buf, 32);
            if (this->_data_cb != nullptr && read > 0) {
                std::vector<uint8_t> vec;
                vec.resize(static_cast<unsigned int>(read));
                memcpy(vec.data(), buf, static_cast<size_t>(read));
                this->_data_cb(vec);
            }
        }
        delete[] buf;
        LogV(TAG, "reader thread terminated");
    }


}