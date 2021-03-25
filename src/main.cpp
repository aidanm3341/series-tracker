#include <ncurses.h>

#include <cursesapp.h>
#include <window.h>

#include <seriesView.h>
#include <seriesController.h>
#include <seriesModel.h>

#include <seriesDAL.h>
#include <SQLiteSeriesDAL.h>
#include <logger.h>

#include <string>
#include <vector>

int main()
{
    Logger logger;

    SeriesDAL *dal;
    SQLiteSeriesDAL sqldal = SQLiteSeriesDAL();
    dal = &sqldal;

    dal->loadSeries();

    CursesApp app;

    SeriesModel model;
    SeriesView view(model);
    SeriesController controller(view, model);

    refresh();
    view.refresh();

    controller.startLoop();


    return 0;
}


