#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

class Window
{
    int width, height, y, x;
    WINDOW* local_win;

    public:
        Window(int height, int width, int y, int x);
        ~Window();

        WINDOW* getWINDOW();
};

#endif
