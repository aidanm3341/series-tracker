#include <ncurses.h>
#include "window.h"
#include "cursesapp.h"

int main()
{
    CursesApp app;

    printw("Series Tracker\n");
    Window win(3, 10, 5, 5);
    refresh();

    win.show();


    // WINDOW *local_win;
	// local_win = newwin(10, 2, 2, 2);
	// box(local_win, 0 , 0);		/* 0, 0 gives default characters 
	// 				 * for the vertical and horizontal
	// 				 * lines			*/
	// wrefresh(local_win);		/* Show that box 		*/

    getch();

    // wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	// wrefresh(local_win);
	// delwin(local_win);

    return 0;
}



