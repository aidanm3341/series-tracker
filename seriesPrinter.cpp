#include "seriesPrinter.h"

SeriesPrinter::SeriesPrinter(std::vector<Series> srs) : series(srs), maxNameLength(0)
{
    for (size_t i = 0; i < series.size(); i++)
    {
        if(series[i].getName().length() > maxNameLength)
            maxNameLength = series[i].getName().length();
    }
    
}

std::string SeriesPrinter::createWatchedBoxesString(int noOfSeries)
{
    std::string output = "  ";
    for (size_t i = 0; i < noOfSeries; i++)
    {
        output += "[ ]  ";
    }
    return output;
}

std::string SeriesPrinter::toString()
{
    std::string output;
    for (size_t i = 0; i < series.size(); i++)
    {
        output += series[i].getName() 
               += std::string(maxNameLength - series[i].getName().length(), ' ') 
               += createWatchedBoxesString(series[i].getNoOfSeries());
        output += "\n";
    }
    
    return output;
}