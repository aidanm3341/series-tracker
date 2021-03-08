#include "series.h"

Series::Series(std::string name, int noOfSeries)
{
    this->name = name;
    this->noOfSeries = noOfSeries;
}

Series::~Series()
{

}

std::string Series::toString()
{
    std::string output = name + " -";
    for (size_t i = 0; i < noOfSeries; i++)
    {
        output += "  [ ]";
    }
    return output;
}