#include "cursesapp.h"
#include <ncurses.h>

CursesApp::CursesApp()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
}

CursesApp::~CursesApp()
{
    endwin();
}