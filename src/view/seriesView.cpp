#include <seriesView.h>
#include <window.h>

#include <sstream>
#include <math.h>
#include <algorithm>

SeriesView::SeriesView(SeriesModel& m) : cols(getmaxx(stdscr)), rows(getmaxy(stdscr)), 
                                                    model(m), maxNameLength(0), 
                                                    titleWindow (3     , cols, 0, 0), 
                                                    seriesWindow(rows-6, cols, 3, 0), 
                                                    inputWindow (3     , cols, rows-3, 0),
                                                    pageSize(0)
{
    titleWindow.print(TITLE);

    updateMaxNameLength();
    updatePageSize();
}

inline std::string SeriesView::spaces(int numberOfSpaces)
{
    return std::string(numberOfSpaces, ' ');
}

void SeriesView::updateMaxNameLength()
{
    for (Series s : model.getSeries())
        if(s.getName().length() > maxNameLength)
            maxNameLength = s.getName().length();
}

void SeriesView::updatePageSize()
{
    pageSize = seriesWindow.getRows() - 3;
}

std::string SeriesView::createWatchedBoxesString(Series s)
{
    std::stringstream output;
    output << spaces(SPACE_BETWEEN_NAME_AND_CHECKBOXES);
    for (size_t i = 0; i < s.getNoOfSeries(); i++)
    {
        if(s.haveWatchedSeries(i))
            output << WATCHED_SERIES << spaces(CHECKBOX_SPACING);
        else
            output << UNWATCHED_SERIES << spaces(CHECKBOX_SPACING);
    }
    return output.str();
}

std::string SeriesView::createSeriesNumberBarString()
{
    std::stringstream output;
    output << spaces(maxNameLength) 
           << spaces(SPACE_BETWEEN_NAME_AND_CHECKBOXES);
           

    for (size_t i = 0; i < model.getMaxNumberOfSeries(); i++)
    {
        if(i < 9)
            output << spaces(WATCHED_SERIES.length()/2);
        else
            output << spaces(WATCHED_SERIES.length()/2 - 1);
        output << i+1
               << spaces(WATCHED_SERIES.length()/2)
               << spaces(CHECKBOX_SPACING);
    }
    output << "\n";
    return output.str();
}

void SeriesView::printAllSeriesInRange(int lower, int upper)
{
    upper = std::min(upper, (int) model.getSeries().size()); // for when there is a page with less than a full page size.

    for (int i = lower; i < upper; i++)
    {
        Series s = model.getSeries()[i];
        if(i == model.getActiveItem())
            seriesWindow.printWithAttr(s.getName(), Window::ATTR::REVERSE);
        else
            seriesWindow << s.getName();

        seriesWindow << spaces(maxNameLength - s.getName().length())
               << createWatchedBoxesString(s)
               << "\n";
    }
}

void SeriesView::printCurrentPage()
{
    int currentPage = floor(model.getActiveItem() / pageSize);
    int maxPage = ceil((model.getSeries().size()-1) / pageSize);

    if(currentPage > 0)
        seriesWindow << spaces(maxNameLength/2) << "^\n";
        
    printAllSeriesInRange(currentPage * pageSize, (currentPage+1) * pageSize);

    if(currentPage < maxPage)
        seriesWindow << spaces(maxNameLength/2) << "v\n";
}

void SeriesView::refresh()
{
    seriesWindow.clear();
    updateMaxNameLength();
    updatePageSize();

    seriesWindow << createSeriesNumberBarString();

    printCurrentPage();

    titleWindow.show();
    seriesWindow.show();
    inputWindow.show();
}

std::string SeriesView::promptUser(std::string prompt)
{
    inputWindow << prompt;
    std::string output = inputWindow.input(0, prompt.length());
    inputWindow.clear();
    return output;
}