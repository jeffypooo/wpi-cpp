//
// Created by Jefferson Jones on 11/9/17.
//

#ifndef SPI_HOST_SPI_H
#define SPI_HOST_SPI_H


#include <cstdint>
#include <vector>
#include <functional>
#include <atomic>

namespace wpi {

    enum SPIChannel : int {
        ZERO = 0, ONE = 1
    };

    class SPI {
    public:
        SPI(SPIChannel channel, int speedHz);

        virtual ~SPI() = default;

        SPIChannel GetChannel();

        int GetSpeedHz();

        int GetFileDesc();

        bool IsReady();

        int Transfer(uint8_t *buf, int len);


    private:
        SPIChannel _channel;
        int _speed_hz;
        int _fd;

    };
}


#endif //SPI_HOST_SPI_H
