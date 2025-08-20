//
// Created by parsa on 6/8/25.
//
#include <ctime>
#include "Date.h"
#include <iostream>
#include <cmath>

using namespace std;

Date::Date() {
    time_t current = time(nullptr);
    tm *localTime = localtime(&current);
    year = (localTime->tm_year + 1900);
    month = (localTime->tm_mon + 1);
    day = localTime->tm_mday;
    hour = localTime->tm_hour;
    minute = localTime->tm_min;
}

istream &operator>>(istream &in, Date &p) {
    time_t current = time(nullptr);
    tm *localTime = localtime(&current);
    cout << "Enter year:\n";
    in >> p.year;
    cout << "Enter month:\n";
    in >> p.month;
    cout << "Enter day:\n";
    in >> p.day;
    p.hour = localTime->tm_hour;
    p.minute = localTime->tm_min;
    return in;
}

ostream &operator<<(ostream &out, Date &p) {
    out << p.year << '/' << p.month << '/' << p.day << '\t' << p.hour << ':' << p.minute;
    return out;
}

long Date::operator-(const Date &other) const {
    return std::abs(to_julian_day() - other.to_julian_day());
}

bool Date::operator<(const Date &other) const {
    return to_julian_day() < other.to_julian_day();
}

bool Date::operator>(const Date &other) const {
    return to_julian_day() > other.to_julian_day();
}


long Date::to_julian_day() const {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

Date Date::from_julian_day(long jd) {
    long a = jd + 32044;
    long b = (4 * a + 3) / 146097;
    long c = a - (146097 * b) / 4;
    long d = (4 * c + 3) / 1461;
    long e = c - (1461 * d) / 4;
    long m = (5 * e + 2) / 153;

    int day = e - (153 * m + 2) / 5 + 1;
    int month = m + 3 - 12 * (m / 10);
    int year = 100 * b + d - 4800 + (m / 10);

    return Date(year, month, day);
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d), hour(0), minute(0) {}