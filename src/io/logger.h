//
// Created by Jefferson Jones on 11/10/17.
//

#ifndef SPI_HOST_LOGGER_H
#define SPI_HOST_LOGGER_H

namespace io {

    void LogV(const char *tag, const char *fmt, ...);
    void LogE(const char *tag, const char *fmt, ...);

}

#endif //SPI_HOST_LOGGER_H

