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

        WINDOW* getWINDOW();
        void show();
        void print(std::string str);
};

#endif
