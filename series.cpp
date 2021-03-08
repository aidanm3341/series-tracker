#include "series.h"

Series::Series(std::string n, int numSeries) : name(n), noOfSeries(numSeries) {}

Series::~Series()
{

}

std::string Series::getName()
{
    return name;
}

int Series::getNoOfSeries()
{
    return noOfSeries;
}