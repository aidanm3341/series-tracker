#ifndef SERIES_H
#define SERIES_H

#include <string>
#include <vector>

class Series
{
    std::string name;
    int noOfSeries;
    std::vector<bool> haveWatched;
    int currentSeries;

    public:
        Series(std::string n, int numSeries, int currentSeries);
        Series(std::string name, int noOfSeries);
        Series(const Series& series);
        Series(Series&& series);
        Series& operator=(const Series& series) noexcept;
        Series& operator=(Series&& series) noexcept;
        ~Series();

        const std::string getName();
        const int getNoOfSeries();
        const int getCurrentSeries();
        const bool haveWatchedSeries(int seriesNo);
        void increment();
        void decrement();
};

#endif