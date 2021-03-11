#include <seriesView.h>
#include <window.h>

#include <sstream>

SeriesView::SeriesView(std::vector<Series> srs) : cols(getmaxx(stdscr)), rows(getmaxy(stdscr)), 
                                                    series(srs), maxNameLength(0), activeItem(0), 
                                                    titleWindow(3, cols, 0, 0), seriesWindow(rows-3, cols, 3, 0)
{
    titleWindow.print(title.c_str());

    for (Series s : series)
        if(s.getName().length() > maxNameLength)
            maxNameLength = s.getName().length();
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

void SeriesView::refresh()
{
    for (int i = 0; i < series.size(); i++)
    {
        Series s = series[i];
        if(activeItem==i)
            seriesWindow.printWithAttr(s.getName().c_str(), Window::ATTR::REVERSE);
        else
            seriesWindow << s.getName().c_str();

        seriesWindow << std::string(maxNameLength - s.getName().length(), ' ') .c_str()
               << createWatchedBoxesString(s).c_str()
               << "\n";
    }

    titleWindow.show();
    seriesWindow.show();
}