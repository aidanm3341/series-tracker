#ifndef SQLITESERIESDAL_H
#define SQLITESERIESDAL_H

#include <seriesDAL.h>
#include <sqlite_modern_cpp.h>

class SQLiteSeriesDAL : public SeriesDAL
{
    sqlite::database db;

    public:
        SQLiteSeriesDAL();
        std::vector<Series> loadSeries();
        void saveSeries(std::vector<Series> series);
};

#endif