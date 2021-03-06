#include <ncurses.h>

int main()
{
    initscr();
    clear();
    noecho();
    cbreak();
    
    printw("Series Tracker");
    refresh();
    
    getch();
    endwin();
    return 0;
}

