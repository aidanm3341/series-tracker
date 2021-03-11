#include <seriesModel.h>

SeriesModel::SeriesModel()
{
    series.push_back(Series("Family Guy", 7));
    series.push_back(Series("Phineas and Ferb", 4));

    series[0].setHaveWatched(2, true);
}

std::vector<Series> SeriesModel::getSeries()
{
    return series;
}