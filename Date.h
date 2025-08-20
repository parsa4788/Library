#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H

#include <iostream>

using namespace std;

class Date {
private:
    int year, month, day, hour, minute;
public:
    Date();

    Date(int y, int m, int d);

    friend istream &operator>>(istream &in, Date &p);

    friend ostream &operator<<(ostream &out, Date &p);

    bool operator<(const Date &other)const;

    bool operator>(const Date &other)const;

    long operator-(const Date &other) const;

    long to_julian_day() const;

    Date from_julian_day(long jd);
};

#endif
