#ifndef SERIESPRINTER_H
#define SERIESPRINTER_H

#include <vector>
#include "series.h"
#include <string>

class SeriesPrinter
{
    std::vector<Series> series;
    int maxNameLength;

    std::string createWatchedBoxesString(int noOfSeries);

    public:
        SeriesPrinter(std::vector<Series> series);
        std::string toString();
};

#endif