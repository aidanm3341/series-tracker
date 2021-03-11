#include <seriesModel.h>

SeriesModel::SeriesModel()
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

void SeriesModel::incrementSeries(int seriesNumber)
{
    series[seriesNumber].increment();
}

void SeriesModel::decrementSeries(int seriesNumber)
{
    series[seriesNumber].decrement();
}