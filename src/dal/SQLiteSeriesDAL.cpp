#include <SQLiteSeriesDAL.h>

SQLiteSeriesDAL::SQLiteSeriesDAL() : db(sqlite::database("series.db"))
{}

std::vector<Series> SQLiteSeriesDAL::loadSeries()
{
    try
    {
        db << "SELECT name,  FROM Series;"
        >> [&](std::string name, int maxSeries, int currentSeries) {
            // breakpoint
        };
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return std::vector<Series>();
}

void SQLiteSeriesDAL::saveSeries(std::vector<Series> series)
{

}

