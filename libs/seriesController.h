#ifndef SERIESCONTROLLER_H
#define SERIESCONTROLLER_H

#include <seriesView.h>

class SeriesController
{
    SeriesView& view;
    
    public:
        SeriesController(SeriesView& view);

        void startLoop();
};

#endif