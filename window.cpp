#include "window.h"
#include <ncurses.h>
#include <iostream>

Window::Window(int height, int width, int y, int x)
{    
    local_win = newwin(height, width, y, x);
	box(local_win, 0 , 0); /* 0, 0 gives default characters 
					        * for the vertical and horizontal
					        * lines			                */
}

void Window::show()
{
    wrefresh(local_win); 
}

Window::~Window()
{
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // You first have to set the border to be nothing, or it will linger
	wrefresh(local_win);
	delwin(local_win);
}

WINDOW* Window::getWINDOW()
{
	return local_win;
}