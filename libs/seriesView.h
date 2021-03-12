#ifndef SERIESPRINTER_H
#define SERIESPRINTER_H

#include <vector>
#include <series.h>
#include <window.h>
#include <seriesModel.h>
#include <string>

const static std::string title = "Series Tracker"; 

class SeriesView
{
    int cols, rows;
    Window seriesWindow, titleWindow;
    SeriesModel& model;
    int maxNameLength;

    std::string createWatchedBoxesString(Series s);

    public:
        SeriesView(SeriesModel& model);
        void refresh();
        void scrollUp();
        void scrollDown();
        void clear();
};

#endif