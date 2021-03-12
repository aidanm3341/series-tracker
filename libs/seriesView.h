#ifndef SERIESPRINTER_H
#define SERIESPRINTER_H

#include <vector>
#include <series.h>
#include <window.h>
#include <seriesModel.h>
#include <string>

const static std::string TITLE = "Series Tracker"; 

const static std::string UNWATCHED_SERIES = "[ ]";
const static std::string WATCHED_SERIES   = "[X]";
const static int CHECKBOX_SPACING = 2;
const static int SPACE_BETWEEN_NAME_AND_CHECKBOXES = 3;

class SeriesView
{
    int cols, rows;
    Window seriesWindow, titleWindow, inputWindow;
    SeriesModel& model;
    int maxNameLength;

    std::string createWatchedBoxesString(Series s);
    std::string createSeriesNumberBarString();

    public:
        SeriesView(SeriesModel& model);
        void refresh();
        void clear();
        std::string promptUser(std::string prompt);
};

#endif