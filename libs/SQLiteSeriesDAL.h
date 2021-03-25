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
        void saveSeries(Series series);
        void deleteSeries(Series series);
};

#endif