#include <seriesModel.h>

SeriesModel::SeriesModel() : activeItem(0)
{
    series.push_back(Series("Family Guy", 7));
    series.push_back(Series("Phineas and Ferb", 4));
    series.push_back(Series("Game Of Thrones", 8));
    series.push_back(Series("WandaVision", 1));
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
}