#include <window.h>
#include <ncurses.h>
#include <iostream>

Window::Window(int height, int width, int y, int x) : highlight(false)
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

void Window::print(const char * str)
{
    wprintw(contentWindow, str);
}

void Window::toggleHighlight()
{
    highlight = !highlight;
    if(highlight)
        wattron(contentWindow, A_REVERSE);
    else
        wattroff(contentWindow, A_REVERSE);
}

Window::~Window()
{
    wborder(borderWindow, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // You first have to set the border to be nothing, or it will linger
	wrefresh(borderWindow);
	delwin(borderWindow);
    delwin(contentWindow);
}

Window& operator<<(Window& win, const char * str)
{
    win.print(str);
    return win;
}

