#include <seriesView.h>
#include <window.h>

#include <sstream>

SeriesView::SeriesView(SeriesModel& m) : cols(getmaxx(stdscr)), rows(getmaxy(stdscr)), 
                                                    model(m), maxNameLength(0), activeItem(0), 
                                                    titleWindow(3, cols, 0, 0), seriesWindow(rows-3, cols, 3, 0)
{
    titleWindow.print(title.c_str());

    for (Series s : model.getSeries())
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
    clear();
    for (int i = 0; i < model.getSeries().size(); i++)
    {
        Series s = model.getSeries()[i];
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

void SeriesView::scrollUp()
{
    activeItem--;
    if(activeItem < 0)
        activeItem = model.getSeries().size()-1;
    refresh();
}

void SeriesView::scrollDown()
{
    activeItem++;
    if(activeItem >= model.getSeries().size())
        activeItem = 0;
    refresh();
}

void SeriesView::clear()
{
    seriesWindow.clear();
}

int SeriesView::getActiveItemNumber()
{
    return activeItem;
}