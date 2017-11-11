//
// Created by Jefferson Jones on 11/9/17.
//

#ifndef SPI_HOST_SPI_H
#define SPI_HOST_SPI_H


#include <cstdint>
#include <vector>
#include <functional>

namespace io {

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

        void Start();

        void Stop();

        void SetDataHandler(std::function<void(std::vector<uint8_t>)> func);


    private:
        SPIChannel _channel;
        int _speed_hz;
        int _fd;
        std::thread *_reader_thr;
        std::function<void(std::vector<uint8_t>)> _data_cb;
        void ReaderThreadLoop();

    };
}


#endif //SPI_HOST_SPI_H
