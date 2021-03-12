#include <window.h>
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

void Window::print(const char * str)
{
    wprintw(contentWindow, str);
}

void Window::printWithAttr(const char * str, ATTR attr)
{
    wattron(contentWindow, attr);
    print(str);
    wattroff(contentWindow, attr);
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

void Window::clear()
{
    werase(contentWindow);
}

void Window::move(int y, int x)
{
    wmove(contentWindow, y, x);
}

std::string Window::input(int y, int x)
{
    curs_set(1);
    echo();

    char input[100] = {};
    mvwgetstr(contentWindow, y, x, input);

    curs_set(0);
    noecho();
    return std::string(input);
}
