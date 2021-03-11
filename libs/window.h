#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <string>

class Window
{
    WINDOW* borderWindow;
    WINDOW* contentWindow;

    public:
        enum ATTR {REVERSE=A_REVERSE, BOLD=A_BOLD};

        Window(int height, int width, int y, int x);
        ~Window();

        void show();
        void print(const char * str);
        void printWithAttr(const char * str, ATTR attr);
};

Window& operator<<(Window& win, const char * str);

#endif
