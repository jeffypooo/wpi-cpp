#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstring>
#include "../io/spi.h"
#include "../io/logger.h"

using namespace std;

static const int SPI_SPD_HZ = 1000000;
static const char *TAG = "MAIN";


int main(int argc, char **argv) {
    auto *spi = new io::SPI(io::SPIChannel::ZERO, SPI_SPD_HZ);
    if (!spi->IsReady()) {
        io::LogV(TAG, "spi failed to init, exiting...");
        return -1;
    }
    auto *str = "The quick brown fox jumps over the lazy dog.";
    auto str_len = strlen(str);
    auto *buf = new uint8_t[str_len];
    memcpy(buf, str, str_len);
    spi->Transfer(buf, str_len);
    delete[] buf;
    return 0;

}