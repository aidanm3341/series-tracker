#include <seriesController.h>

SeriesController::SeriesController(SeriesView& v, SeriesModel& m) : view(v) , model(m)
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
            case KEY_RIGHT:
                model.incrementSeries(view.getActiveItemNumber());
                view.refresh();
                break;
		}

        //view.refresh();
    }
}