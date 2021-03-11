#include "cursesapp.h"
#include <ncurses.h>

CursesApp::CursesApp()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
}

CursesApp::~CursesApp()
{
    endwin();
}