#include <SQLiteSeriesDAL.h>

SQLiteSeriesDAL::SQLiteSeriesDAL() : db(sqlite::database("series.db"))
{
    db <<
         "CREATE TABLE IF NOT EXISTS Series ("
         "   _id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
         "   maxSeries INT,"
         "   currentSeries INT"
         ");";
}

std::vector<Series> SQLiteSeriesDAL::loadSeries()
{
    try
    {
        db << "SELECT name, maxSeries, currentSeries FROM Series;"
        >> [&](std::string name, int maxSeries, int currentSeries) {
            std::cout << name << std::endl;
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

