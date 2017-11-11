#include <iostream>
#include <thread>
#include <unistd.h>
#include "../io/spi.h"
#include "../io/logger.h"

using namespace std;

static const char *TAG = "MAIN";


int main(int argc, char **argv) {
    auto *spi = new io::SPI(io::SPIChannel::ZERO, 5000000);
    if (!spi->IsReady()) {
        io::LogV(TAG, "spi failed to init, exiting...");
        return -1;
    }
    spi->SetDataHandler([](std::vector<uint8_t> data) {
        io::LogV(TAG, "READ %d", data.size());
    });
    spi->Start();
    sleep(1);
    auto *write_data = new uint8_t[32];
    spi->Write(write_data, 32);
    spi->Stop();
    return 0;

}