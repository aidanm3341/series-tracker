#include <seriesView.h>
#include <window.h>

#include <sstream>

SeriesView::SeriesView(Window& win, std::vector<Series> srs) : window(win), series(srs), maxNameLength(0), activeItem(0)
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

void SeriesView::refresh()
{
    for (int i = 0; i < series.size(); i++)
    {
        Series s = series[i];
        if(activeItem==i)
            window.printWithAttr(s.getName().c_str(), Window::ATTR::REVERSE);
        else
            window << s.getName().c_str();

        window << std::string(maxNameLength - s.getName().length(), ' ') .c_str()
               << createWatchedBoxesString(s).c_str()
               << "\n";
    }
}