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
        void print(std::string str);
        void printWithAttr(std::string str, ATTR attr);
        void clear();
        void move(int y, int x);
        std::string input(int y, int x);
        int getRows();
};

Window& operator<<(Window& win, std::string str);

#endif
