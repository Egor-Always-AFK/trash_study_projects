#include "../incl/AutoService.h"

AutoService::AutoService() : _dataDay(0), _dataMonth(0), _dataYear(0), _autoNumber("NAN"), _normHour(0)
{   }

AutoService::AutoService(int dataDay, int dataMonth, int dataYear, std::string autoNumber, int normHour) : _dataDay(dataDay), _dataMonth(dataMonth), _dataYear(dataYear), _autoNumber(autoNumber), _normHour(normHour)
{   }

AutoService::AutoService(const AutoService &cpy) : _dataDay(cpy._dataDay), _dataMonth(cpy._dataMonth), _dataYear(cpy._dataYear), _autoNumber(cpy._autoNumber), _normHour(cpy._normHour)
{   }

AutoService::~AutoService()
{   }

AutoService AutoService::operator=(const AutoService &cpy)
{
    _dataDay = cpy._dataDay;
    _dataMonth = cpy._dataMonth;
    _dataYear = cpy._dataYear;
    _autoNumber = cpy._autoNumber;
    _normHour = cpy._normHour;
    return *this;
}

void AutoService::setDataDay(int dataDay) 
{
    _dataDay = dataDay;
}

void AutoService::setDataMonth(int dataMonth)
{
    _dataMonth = dataMonth;
}

void AutoService::setDataYear(int dataYear)
{
    _dataYear = dataYear;
}

void AutoService::setAutoNumber(std::string autoNumber)
{
    _autoNumber = autoNumber;
}

void AutoService::setNormHour(int normHour)
{
    _normHour = normHour;
}

int AutoService::getDataDay()
{
    return _dataDay;
}

int AutoService::getDataMonth()
{
    return _dataMonth;
}

int AutoService::getDataYear()
{
    return _dataYear;
}

std::string AutoService::getNumber()
{
    return _autoNumber;
}

int AutoService::getNormHour()
{
    return _normHour;
}

std::ostream &operator<<(std::ostream &out, AutoService &src)
{
    out << "Date: " << src._dataDay << '.' << src._dataMonth << '.' << src._dataYear << 
    "\nNumber: " << src._autoNumber << "\nNorm hour: " << src._normHour << std::endl;
    return (out);
}