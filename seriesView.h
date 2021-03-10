#ifndef SERIESPRINTER_H
#define SERIESPRINTER_H

#include <vector>
#include "series.h"
#include "window.h"
#include <string>

class SeriesView
{
    Window& window;
    const std::vector<Series> series;
    int maxNameLength;
    int activeItem;

    std::string createWatchedBoxesString(Series s);

    public:
        SeriesView(Window& win, std::vector<Series> series);
        void refresh();
};

#endif