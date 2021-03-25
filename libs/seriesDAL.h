#ifndef SERIESDAL_H
#define SERIESDAL_H

#include <series.h>
#include <vector>

class SeriesDAL
{
    public:
        virtual std::vector<Series> loadSeries() = 0;
        virtual void saveSeries(Series series) = 0;
        virtual void deleteSeries(Series series) = 0;
};

#endif