#include <SQLiteSeriesDAL.h>
#include <cstdlib>

SQLiteSeriesDAL::SQLiteSeriesDAL() : db(sqlite::database(std::string(std::getenv("HOME")) + "/.series.db"))
{
    try
    {
        db << "CREATE TABLE IF NOT EXISTS Series (_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, name VARCHAR(255), maxSeries INT, currentSeries INT);";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::vector<Series> SQLiteSeriesDAL::loadSeries()
{
    std::vector<Series> series;
    try
    {
        db << "SELECT name, maxSeries, currentSeries FROM Series;"
        >> [&](std::string name, int maxSeries, int currentSeries) {
            series.push_back(Series(name, maxSeries, currentSeries));
        };
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return series;
}

void SQLiteSeriesDAL::saveSeries(Series s)
{
    try
    {
        db << "INSERT INTO Series(name, maxSeries, currentSeries) VALUES (?, ?, ?);"
        << s.getName()
        << s.getNoOfSeries()
        << s.getCurrentSeries();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void SQLiteSeriesDAL::saveAllSeries(std::vector<Series> series)
{
    try
    {
        for(Series s : series)
        {
            db << "INSERT INTO Series(name, maxSeries, currentSeries) VALUES (?, ?, ?);"
            << s.getName()
            << s.getNoOfSeries()
            << s.getCurrentSeries();
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void SQLiteSeriesDAL::setCurrentSeries(Series s)
{
    try
    {
        db << "UPDATE Series SET currentSeries = ? WHERE name = ?;"
           << s.getCurrentSeries()
           << s.getName();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void SQLiteSeriesDAL::deleteSeries(Series s)
{
    try
    {
        db << "DELETE FROM Series WHERE name = ?;"
        << s.getName();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

