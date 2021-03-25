#include <seriesModel.h>
#include <SQLiteSeriesDAL.h>

SeriesModel::SeriesModel() : activeItem(0)
{
    dal = &sqldal;

    series = dal->loadSeries();
}

std::vector<Series>& SeriesModel::getSeries()
{
    return series;
}

void SeriesModel::incrementSeries()
{
    series[activeItem].increment();
}

void SeriesModel::decrementSeries()
{
    series[activeItem].decrement();
}

int SeriesModel::getActiveItem()
{
    return activeItem;
}

void SeriesModel::setActiveItem(int newActiveItem)
{
    activeItem = newActiveItem;
}

void SeriesModel::addNewSeries(std::string name, int numOfSeries)
{
    Series s(name, numOfSeries);
    series.push_back(s);

    dal->saveSeries(s);    
}

int SeriesModel::getMaxNumberOfSeries()
{
    int maxNumberOfSeries = 0;
    for(Series s : series)
        if(s.getNoOfSeries() > maxNumberOfSeries)
            maxNumberOfSeries = s.getNoOfSeries();
    
    return maxNumberOfSeries;
}