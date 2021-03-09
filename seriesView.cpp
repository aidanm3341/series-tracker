#include "seriesView.h"
#include "sstream"

SeriesView::SeriesView(std::vector<Series> srs) : series(srs), maxNameLength(0), activeItem(0)
{
    for (Series s : series)
    {
        if(s.getName().length() > maxNameLength)
            maxNameLength = s.getName().length();
    }
}

std::string SeriesView::createWatchedBoxesString(Series s)
{
    std::stringstream output;
    output << "   ";
    for (size_t i = 0; i < s.getNoOfSeries(); i++)
    {
        if(s.haveWatchedSeries(i))
            output << "[X]  ";
        else
            output << "[ ]  ";
    }
    return output.str();
}

const std::string SeriesView::toString()
{
    std::stringstream output;
    for (Series s : series)
    {
        output << s.getName()
               << std::string(maxNameLength - s.getName().length(), ' ') 
               << createWatchedBoxesString(s)
               << "\n";
    }
    
    return output.str();
}