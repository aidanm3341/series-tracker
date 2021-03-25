#include <series.h>

Series::Series(std::string n, int numSeries) : name(n), noOfSeries(numSeries), haveWatched(std::vector<bool>(numSeries, false)), currentSeries(0) {}

Series::Series(const Series& s) : name(s.name), noOfSeries(s.noOfSeries), haveWatched(s.haveWatched), currentSeries(s.currentSeries)
{}

Series::Series(Series&& s) : name(s.name), noOfSeries(s.noOfSeries), haveWatched(s.haveWatched), currentSeries(s.currentSeries)
{}

Series& Series::operator=(const Series& s) noexcept
{
    name = s.name;
    noOfSeries = s.noOfSeries;
    haveWatched = s.haveWatched;
    currentSeries = s.currentSeries;
    return *this;
}

Series& Series::operator=(Series&& s) noexcept
{
    name = s.name;
    noOfSeries = s.noOfSeries;
    haveWatched = s.haveWatched;
    currentSeries = s.currentSeries;
    return *this;
}

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

const int Series::getCurrentSeries()
{
    return currentSeries;
}

const bool Series::haveWatchedSeries(int seriesNo)
{
    return haveWatched[seriesNo];
}

void Series::increment()
{
    haveWatched[currentSeries] = true;
    if(currentSeries < noOfSeries)
        currentSeries++;
}

void Series::decrement()
{
    if(currentSeries > 0)
        currentSeries--;
    haveWatched[currentSeries] = false;
}