#include <ncurses.h>
#include "window.h"
#include "series.h"
#include "seriesView.h"
#include "cursesapp.h"
#include <string>
#include <vector>

std::string title = "Series Tracker"; 

int cols, rows;

void generateSeriesWindow(Window &seriesWindow);

int main()
{
    CursesApp app;
    cols = getmaxx(stdscr);
    rows = getmaxy(stdscr);

    Window titleWindow(3, cols, 0, 0);
    titleWindow.print(title);

    Window seriesWindow(rows-3, cols, 3, 0);
    generateSeriesWindow(seriesWindow);

    refresh();

    titleWindow.show();
    seriesWindow.show();

    getch();
    return 0;
}

void generateSeriesWindow(Window &seriesWindow)
{
    Series phineasferb("Phineas and Ferb", 4);

    std::vector<Series> series;
    series.push_back(Series("Family Guy", 7));
    series.push_back(Series("Phineas and Ferb", 4));

    series[0].setHaveWatched(2, true);
    
    SeriesView printer(series);
    seriesWindow.print(printer.toString());
}


