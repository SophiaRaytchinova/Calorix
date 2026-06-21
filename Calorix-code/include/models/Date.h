#pragma once
#include <string>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    static Date today();
    static Date fromString(const std::string& value);
    std::string toString() const;
    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;
};
