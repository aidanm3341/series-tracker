#ifndef SERIES_H
#define SERIES_H

#include <string>

class Series
{
    const std::string name;
    const int noOfSeries;

    public:
        Series(std::string name, int noOfSeries);
        ~Series();

        const std::string getName();
        const int getNoOfSeries();
};

#endif