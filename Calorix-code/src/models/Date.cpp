#include "../../include/models/Date.h"
#include <ctime> //за текущат дата
#include <sstream>
#include <iomanip>
#include <stdexcept>

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::getDay() const 
{ 
    return day; 
}

int Date::getMonth() const 
{ 
    return month; 
}

int Date::getYear() const 
{ 
    return year; 
}

Date Date::today() 
{ 
    std::time_t now = std::time(nullptr); 
    std::tm* t = std::localtime(&now); 
    return Date(t->tm_mday, t->tm_mon + 1, t->tm_year + 1900); 
}

Date Date::fromString(const std::string& value) 
{ 
    int y = 0, m = 0, d = 0; 
    char c1 = 0, c2 = 0; 
    std::stringstream ss(value); 

    if (value.find('-') != std::string::npos) 
    {
        ss >> y >> c1 >> m >> c2 >> d; 
    }
    else { ss >> d >> c1 >> m >> c2 >> y; 
    } 
    if (!ss || d < 1 || m < 1 || m > 12 || y < 1900) throw std::invalid_argument("Invalid date. Use YYYY-MM-DD."); 
    return Date(d, m, y); 
}

std::string Date::toString() const 
{ 
    std::ostringstream os; 
    os << std::setw(4) << std::setfill('0') << year << '-' << std::setw(2) << month << '-' << std::setw(2) << day; 
    return os.str(); 
}

bool Date::operator==(const Date& o) const 
{ 
    return day == o.day && month == o.month && year == o.year; 
}
bool Date::operator<(const Date& o) const 
{ 
    if (year != o.year) 
    {
        return year < o.year;
    }
    if (month != o.month) 
    {
        return month < o.month;
    }
    return day < o.day;
}
