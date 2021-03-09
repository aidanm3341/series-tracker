#include "series.h"

Series::Series(std::string n, int numSeries) : name(n), noOfSeries(numSeries) {}

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