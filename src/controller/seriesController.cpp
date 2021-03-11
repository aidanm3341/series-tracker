#include <seriesController.h>

SeriesController::SeriesController(SeriesView& v) : view(v) 
{}

void SeriesController::startLoop()
{
    int ch;

    while((ch = getch()) != KEY_F(1))
    {
        //std::cout << "Hello bitch" << std::endl;
        switch(ch)
		{	
			case KEY_UP:
				view.scrollUp();
				break;
			case KEY_DOWN:
				view.scrollDown();
				break;	
		}

        //view.refresh();
    }
}