#include "window.h"
#include <ncurses.h>
#include <iostream>

Window::Window(int height, int width, int y, int x)
{
    this->height = height;
    this->width = width;
    this->y = y;
    this->x = x;
    printw("New window!!\n");
}

Window::~Window()
{
    std::cout << "window deleted" << std::endl;
}
