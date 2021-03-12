#include <seriesModel.h>

SeriesModel::SeriesModel() : activeItem(0), maxNumberOfSeries(0)
{
    addNewSeries("Family Guy", 7);
    addNewSeries("Phineas and Ferb", 4);
    addNewSeries("Game Of Thrones", 8);
    addNewSeries("WandaVision", 1);
}

std::vector<Series>& SeriesModel::getSeries()
{
    return series;
}

void SeriesModel::incrementSeries()
{
    series[activeItem].increment();
}

void SeriesModel::decrementSeries()
{
    series[activeItem].decrement();
}

int SeriesModel::getActiveItem()
{
    return activeItem;
}

void SeriesModel::setActiveItem(int newActiveItem)
{
    activeItem = newActiveItem;
}

void SeriesModel::addNewSeries(std::string name, int numOfSeries)
{
    series.push_back(Series(name, numOfSeries));
    if(numOfSeries > maxNumberOfSeries)
        maxNumberOfSeries = numOfSeries;
}

int SeriesModel::getMaxNumberOfSeries()
{
    return maxNumberOfSeries;
}