#ifndef SERIESPRINTER_H
#define SERIESPRINTER_H

#include <vector>
#include <series.h>
#include <window.h>
#include <string>

const static std::string title = "Series Tracker"; 

class SeriesView
{
    int cols, rows;
    Window seriesWindow, titleWindow;
    const std::vector<Series> series;
    int maxNameLength;
    int activeItem;

    std::string createWatchedBoxesString(Series s);

    public:
        SeriesView(std::vector<Series> series);
        void refresh();
};

#endif