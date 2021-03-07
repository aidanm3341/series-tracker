#include <ncurses.h>
#include "window.h"
#include "cursesapp.h"

int main()
{
    CursesApp app;
    
    printw("Series Tracker\n");
    Window win(3, 10, 5, 5);
    refresh();
    
    getch();
    return 0;
}



