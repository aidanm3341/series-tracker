#include <ncurses.h>

#include <cursesapp.h>
#include <window.h>

#include <seriesView.h>
#include <seriesController.h>
#include <seriesModel.h>

#include <string>
#include <vector>

int main()
{
    CursesApp app;

    SeriesModel model;
    SeriesView view(model);
    SeriesController controller(view, model);

    refresh();
    view.refresh();

    controller.startLoop();

    return 0;
}


