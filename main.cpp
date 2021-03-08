#include <ncurses.h>
#include "window.h"
#include "series.h"
#include "cursesapp.h"
#include <string>

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
    Series familyguy("Family Guy", 7);
    seriesWindow.print(familyguy.toString());

    Series phineasferb("Phineas and Ferb", 4);
    seriesWindow.print(phineasferb.toString());
}


