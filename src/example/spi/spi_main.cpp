#include <iostream>
#include <thread>
#include <cstring>
#include <io/io.h>
#include <io/spi.h>
#include <io/logger.h>


#define ERR_SPI_INIT_FAILURE    (-1)
#define ERR_SPI_XFER_FAILURE    (-2)
#define DEFAULT_MSG             "The quick brown fox jumps over the lazy dog."
#define DEFAULT_SPI_SPD         100000

using namespace io;

static const char *TAG = "MAIN";

void SPIDemoLoop(const std::string &msg, io::SPI &spi);

int main(int argc, char **argv) {
    // default values
    std::string message(DEFAULT_MSG);
    int speed = DEFAULT_SPI_SPD;
    // some rudimentary args processing
    // -m "message here" to change the message sent via SPI
    // -s <speed_hz> to change the SPI speed
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp("-m", argv[i]) == 0 && (i + 1) < argc) {
                message = argv[i + 1];
            }
            if (strcmp("-s", argv[i]) == 0 && (i + 1) < argc) {
                std::string speed_str = argv[i + 1];
                speed = std::stoi(speed_str);
            }
        }
    }
    // init the driver and check that it configured without error
    SPI spi(SPIChannel::ZERO, speed);
    if (!spi.IsReady()) {
        LogE(TAG, "SPI setup failed, exiting...");
        exit(ERR_SPI_INIT_FAILURE);
    }
    LogV(TAG, "using message: %s", message.c_str());
    SPIDemoLoop(message, spi);
    return 0;

}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

void SPIDemoLoop(const std::string &msg, io::SPI &spi) {
    auto str_size = msg.size();
    while (true) {
        // wait for the user to press enter to send the data
        LogV(TAG, "press enter to send data...");
        char temp = 'x';
        while (temp != '\n') {
            std::cin.get(temp);
        }
        // send data, exiting if a failure occurs
        auto *data_buf = new uint8_t[str_size];
        memcpy(data_buf, msg.data(), str_size);
        int xfer_cnt = spi.Transfer(data_buf, str_size);
        if (xfer_cnt < 0) {
            LogE(TAG, "SPI::Transfer failed, exiting...");
            exit(ERR_SPI_XFER_FAILURE);
        }
        printf("returned buffer:\n");
        for (int i = 0; i < xfer_cnt; ++i) {
            printf("%d", data_buf[i]);
        }
        printf("\n");
        delete[] data_buf;
    }
}

#pragma clang diagnostic pop