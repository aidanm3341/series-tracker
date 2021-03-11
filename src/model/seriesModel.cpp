#include <seriesModel.h>

SeriesModel::SeriesModel()
{
    series.push_back(Series("Family Guy", 7));
    series.push_back(Series("Phineas and Ferb", 4));
}

std::vector<Series>& SeriesModel::getSeries()
{
    return series;
}

void SeriesModel::incrementSeries(int seriesNumber)
{
    series[seriesNumber].watchNext();
}