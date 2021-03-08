#include "window.h"
#include <ncurses.h>
#include <iostream>

Window::Window(int height, int width, int y, int x)
{    
    borderWindow = newwin(height, width, y, x);
	box(borderWindow, 0 , 0);

    contentWindow = newwin(height-2, width-5, y+1, x+3);
}

void Window::show()
{
    wrefresh(borderWindow); 
    wrefresh(contentWindow);
}

void Window::print(std::string str)
{
    wprintw(contentWindow, (str + "\n").c_str());
}

Window::~Window()
{
    wborder(borderWindow, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // You first have to set the border to be nothing, or it will linger
	wrefresh(borderWindow);
	delwin(borderWindow);
    delwin(contentWindow);
}

WINDOW* Window::getWINDOW()
{
	return contentWindow;
}