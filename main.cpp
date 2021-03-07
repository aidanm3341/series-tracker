#include <ncurses.h>
#include "window.h"
#include "cursesapp.h"
#include <string>

std::string title = "Series Tracker"; 

int main()
{
    CursesApp app;
    int cols = getmaxx(stdscr);
    int rows = getmaxy(stdscr);

    Window titleWindow(3, cols, 0, 0);
    titleWindow.print(title);

    Window seriesWindow(rows-3, cols, 3, 0);
    seriesWindow.print("Family Guy - [X]  [X]  [ ]  [ ]");

    refresh();

    titleWindow.show();
    seriesWindow.show();

    getch();
    return 0;
}



