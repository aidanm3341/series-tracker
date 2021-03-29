#include <seriesController.h>
#include <exception>
#include <iostream>

SeriesController::SeriesController(SeriesView& v, SeriesModel& m) : view(v) , model(m)
{}

void SeriesController::add()
{
    std::string name;
    bool isValidInput = true;
    name = view.promptUser("Name - ");
    for(Series s : model.getSeries())
        if(name == s.getName())
            isValidInput = false;
    
    while(!isValidInput)
    {
        name = view.promptUser("Series with that name exists already, try again - ");
        for(Series s : model.getSeries())
        if(name == s.getName())
            isValidInput = false;
    }
    
    int noOfSeries = 0;
    isValidInput = false;
    try
    {
        noOfSeries = std::stoi(view.promptUser("Number of series - "));
    }
    catch(std::exception err)
    {
        while(!isValidInput)
        {
            try
            {
                noOfSeries = std::stoi(view.promptUser("Enter a valid number of series - "));
                isValidInput = true;
            }
            catch(std::exception err)
            {}
        }
    }

    model.addNewSeries(name, noOfSeries);
    view.refresh();
}

void SeriesController::remove()
{
    std::string response;
    bool isValidInput = false;
    while(!isValidInput)
    {
        response = view.promptUser("Are you sure you want to delete? (y/n) - ");
        if(response == "y" || response == "n")
            isValidInput = true;
    }
    if(response == "y")
    {
        model.deleteActiveSeries();
    }
    view.refresh();
}

void SeriesController::startLoop()
{
    int ch;

    while((ch = getch()) != KEY_F(1))
    {
        //std::cout << "Hello bitch" << std::endl;
        switch(ch)
		{	
			case KEY_UP:
				model.setActiveItem((model.getActiveItem()-1 + model.getSeries().size()) % model.getSeries().size());
                view.refresh();
				break;
			case KEY_DOWN:
				model.setActiveItem((model.getActiveItem()+1) % model.getSeries().size());
                view.refresh();
				break;	
            case KEY_RIGHT:
                model.incrementSeries();
                view.refresh();
                break;
            case KEY_LEFT:
                model.decrementSeries();
                view.refresh();
                break;
            case 'a': 
                add();
                break;
            case 'd': 
                remove();
                break;
		}
    }
}