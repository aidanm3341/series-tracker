#include <ncurses.h>

#include <cursesapp.h>
#include <window.h>

#include <seriesView.h>
#include <seriesController.h>
#include <seriesModel.h>

#include <seriesDAL.h>
#include <SQLiteSeriesDAL.h>

#include <string>
#include <vector>

int main()
{
    //SeriesDAL *dal;
    SQLiteSeriesDAL sqldal = SQLiteSeriesDAL();
    //dal = &sqldal;
    sqldal.loadSeries();

    CursesApp app;

    SeriesModel model;
    SeriesView view(model);
    SeriesController controller(view, model);

    refresh();
    view.refresh();

    controller.startLoop();


    return 0;
}


