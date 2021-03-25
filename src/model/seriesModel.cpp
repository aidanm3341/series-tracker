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
    dal->setCurrentSeries(series[activeItem]);
}

void SeriesModel::decrementSeries()
{
    series[activeItem].decrement();
    dal->setCurrentSeries(series[activeItem]);
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

void SeriesModel::deleteActiveSeries()
{
    dal->deleteSeries(series[activeItem]);
    series.erase(series.begin() + activeItem);
}

int SeriesModel::getMaxNumberOfSeries()
{
    int maxNumberOfSeries = 0;
    for(Series s : series)
        if(s.getNoOfSeries() > maxNumberOfSeries)
            maxNumberOfSeries = s.getNoOfSeries();
    
    return maxNumberOfSeries;
}