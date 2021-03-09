#include "seriesPrinter.h"
#include "sstream"

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
    std::stringstream output;
    for (Series s : series)
    {
        output << s.getName()
               << std::string(maxNameLength - s.getName().length(), ' ') 
               << createWatchedBoxesString(s.getNoOfSeries())
               << "\n";
    }
    
    return output.str();
}