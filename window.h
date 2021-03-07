#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

class Window
{
    WINDOW* local_win;

    public:
        Window(int height, int width, int y, int x);
        ~Window();

        WINDOW* getWINDOW();
        void show();
};

#endif
