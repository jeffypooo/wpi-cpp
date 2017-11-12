#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstring>
#include "../io/spi.h"
#include "../io/logger.h"

#define ERR_SPI_INIT_FAILURE    (-1)
#define ERR_SPI_XFER_FAILURE    (-2)

using namespace io;

static const int SPI_SPD_HZ = 100000;
static const char *TAG = "MAIN";

void SPIDemoLoop(const std::string &msg, io::SPI &spi);

int main(int argc, char **argv) {
    std::string message("The quick brown fox jumps over the lazy dog.");
    int speed = SPI_SPD_HZ;
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
        LogV(TAG, "press enter to send data...");
        char temp = 'x';
        while (temp != '\n') {
            std::cin.get(temp);
        }
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