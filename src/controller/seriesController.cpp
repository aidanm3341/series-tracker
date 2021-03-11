#include <seriesController.h>

SeriesController::SeriesController(SeriesView& v) : view(v) 
{}

void SeriesController::startLoop()
{
    int ch;

    while((ch = getch()) != KEY_EXIT)
    {
        //std::cout << "Hello bitch" << std::endl;
    }
}