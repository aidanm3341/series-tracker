#ifndef SERIESMODEL_H
#define SERIESMODEL_H

#include <vector>
#include <series.h>

class SeriesModel
{
    std::vector<Series> series;
    int activeItem;

    public:
        SeriesModel();
        std::vector<Series>& getSeries();
        void incrementSeries();
        void decrementSeries();
        int getActiveItem();
        void setActiveItem(int newActiveItem);
};

#endif