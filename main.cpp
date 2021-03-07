#include <ncurses.h>
#include "window.h"

int main()
{
    initscr();
    clear();
    noecho();
    cbreak();
    
    printw("Series Tracker\n");
    Window win(0, 0, 0, 0);
    refresh();
    
    getch();
    endwin();
    return 0;
}



