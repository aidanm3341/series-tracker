#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>

class Logger
{
    std::fstream file;

    public:
        Logger();
        ~Logger();
};

#endif