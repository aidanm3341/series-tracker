#include "cursesapp.h"
#include <ncurses.h>

CursesApp::CursesApp()
{
    initscr();
    clear();
    noecho();
    cbreak();
}

CursesApp::~CursesApp()
{
    endwin();
}