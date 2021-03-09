#include "series.h"

Series::Series(std::string n, int numSeries) : name(n), noOfSeries(numSeries), haveWatched(std::vector<bool>(numSeries, false)) {}

Series::~Series()
{

}

const std::string Series::getName()
{
    return name;
}

const int Series::getNoOfSeries()
{
    return noOfSeries;
}

const bool Series::haveWatchedSeries(int seriesNo)
{
    return haveWatched[seriesNo];
}

void Series::setHaveWatched(int seriesNo, bool val)
{
    haveWatched[seriesNo] = val;
}