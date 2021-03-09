#ifndef SERIESPRINTER_H
#define SERIESPRINTER_H

#include <vector>
#include "series.h"
#include <string>

class SeriesView
{
    const std::vector<Series> series;
    int maxNameLength;
    int activeItem;

    std::string createWatchedBoxesString(Series s);

    public:
        SeriesView(std::vector<Series> series);
        const std::string toString();
};

#endif