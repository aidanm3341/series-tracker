#include <seriesView.h>
#include <window.h>

#include <sstream>

SeriesView::SeriesView(SeriesModel& m) : cols(getmaxx(stdscr)), rows(getmaxy(stdscr)), 
                                                    model(m), maxNameLength(0), 
                                                    titleWindow (3     , cols, 0, 0), 
                                                    seriesWindow(rows-6, cols, 3, 0), 
                                                    inputWindow (3     , cols, rows-3, 0)
{
    titleWindow.print(TITLE.c_str());

    updateMaxNameLength();
}

void SeriesView::updateMaxNameLength()
{
    for (Series s : model.getSeries())
        if(s.getName().length() > maxNameLength)
            maxNameLength = s.getName().length();
}

std::string SeriesView::createWatchedBoxesString(Series s)
{
    std::stringstream output;
    output << std::string(SPACE_BETWEEN_NAME_AND_CHECKBOXES, ' ');
    for (size_t i = 0; i < s.getNoOfSeries(); i++)
    {
        if(s.haveWatchedSeries(i))
            output << WATCHED_SERIES << std::string(CHECKBOX_SPACING, ' ');
        else
            output << UNWATCHED_SERIES << std::string(CHECKBOX_SPACING, ' ');
    }
    return output.str();
}

std::string SeriesView::createSeriesNumberBarString()
{
    std::stringstream output;
    output << std::string(maxNameLength, ' ') 
           << std::string(SPACE_BETWEEN_NAME_AND_CHECKBOXES, ' ');
           

    for (size_t i = 0; i < model.getMaxNumberOfSeries(); i++)
    {
        if(i < 9)
            output << std::string(WATCHED_SERIES.length()/2, ' ');
        else
            output << std::string(WATCHED_SERIES.length()/2 - 1, ' ');
        output << i+1
               << std::string(WATCHED_SERIES.length()/2, ' ')
               << std::string(CHECKBOX_SPACING, ' ');
    }
    output << "\n";
    return output.str();
}

void SeriesView::printAllSeries()
{
    for (int i = 0; i < model.getSeries().size(); i++)
    {
        Series s = model.getSeries()[i];
        if(i == model.getActiveItem())
            seriesWindow.printWithAttr(s.getName().c_str(), Window::ATTR::REVERSE);
        else
            seriesWindow << s.getName().c_str();

        seriesWindow << std::string(maxNameLength - s.getName().length(), ' ').c_str()
               << createWatchedBoxesString(s).c_str()
               << "\n";
    }
}

void SeriesView::refresh()
{
    clear();
    updateMaxNameLength();

    seriesWindow << createSeriesNumberBarString().c_str();

    printAllSeries();

    titleWindow.show();
    seriesWindow.show();
    inputWindow.show();
}

void SeriesView::clear()
{
    seriesWindow.clear();
}

std::string SeriesView::promptUser(std::string prompt)
{
    inputWindow << prompt.c_str();
    std::string output = inputWindow.input(0, prompt.length());
    inputWindow.clear();
    return output;
}