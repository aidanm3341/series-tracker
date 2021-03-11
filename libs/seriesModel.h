#ifndef SERIESMODEL_H
#define SERIESMODEL_H

#include <vector>
#include <series.h>

class SeriesModel
{
    std::vector<Series> series;
    public:
        SeriesModel();
        std::vector<Series>& getSeries();
        void incrementSeries(int seriesNumber);
};

#endif