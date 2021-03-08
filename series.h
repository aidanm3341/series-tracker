#ifndef SERIES_H
#define SERIES_H

#include <string>

class Series
{
    std::string name;
    int noOfSeries;

    public:
        Series(std::string name, int noOfSeries);
        ~Series();

        std::string getName();
        int getNoOfSeries();
};

#endif