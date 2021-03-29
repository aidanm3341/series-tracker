#ifndef SERIESCONTROLLER_H
#define SERIESCONTROLLER_H

#include <seriesView.h>
#include <seriesModel.h>

class SeriesController
{
    SeriesView& view;
    SeriesModel& model;

    void add();
    void remove();

    public:
        SeriesController(SeriesView& view, SeriesModel& model);

        void startLoop();
};

#endif