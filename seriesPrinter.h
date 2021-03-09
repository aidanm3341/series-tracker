#ifndef SERIESPRINTER_H
#define SERIESPRINTER_H

#include <vector>
#include "series.h"
#include <string>

class SeriesPrinter
{
    const std::vector<Series> series;
    int maxNameLength;

    std::string createWatchedBoxesString(int noOfSeries);

    public:
        SeriesPrinter(std::vector<Series> series);
        const std::string toString();
};

#endif