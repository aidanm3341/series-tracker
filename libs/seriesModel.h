#ifndef SERIESMODEL_H
#define SERIESMODEL_H

#include <vector>
#include <series.h>

#include <seriesDAL.h>
#include <SQLiteSeriesDAL.h>

class SeriesModel
{
    std::vector<Series> series;
    int activeItem;

    SeriesDAL *dal;
    SQLiteSeriesDAL sqldal;

    public:
        SeriesModel();
        std::vector<Series>& getSeries();
        void incrementSeries();
        void decrementSeries();
        int getActiveItem();
        void setActiveItem(int newActiveItem);
        void addNewSeries(std::string name, int numOfSeries);
        void deleteActiveSeries();

        int getMaxNumberOfSeries();
};

#endif