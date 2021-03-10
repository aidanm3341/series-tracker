#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <string>

class Window
{
    WINDOW* borderWindow;
    WINDOW* contentWindow;

    public:
        Window(int height, int width, int y, int x);
        ~Window();

        void show();
        void print(const char * str);
};

Window& operator<<(Window& win, const char * str);

#endif
