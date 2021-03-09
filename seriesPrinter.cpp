#include "seriesPrinter.h"
#include "sstream"

SeriesPrinter::SeriesPrinter(std::vector<Series> srs) : series(srs), maxNameLength(0)
{
    for (Series s : series)
    {
        if(s.getName().length() > maxNameLength)
            maxNameLength = s.getName().length();
    }
}

std::string SeriesPrinter::createWatchedBoxesString(int noOfSeries)
{
    std::stringstream output;
    output << "   ";
    for (size_t i = 0; i < noOfSeries; i++)
    {
        output << "[ ]  ";
    }
    return output.str();
}

const std::string SeriesPrinter::toString()
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