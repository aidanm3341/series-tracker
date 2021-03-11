#ifndef SERIES_H
#define SERIES_H

#include <string>
#include <vector>

class Series
{
    const std::string name;
    const int noOfSeries;
    std::vector<bool> haveWatched;
    int currentSeries;

    public:
        Series(std::string name, int noOfSeries);
        ~Series();

        const std::string getName();
        const int getNoOfSeries();
        const bool haveWatchedSeries(int seriesNo);
        void watchNext();
};

#endif