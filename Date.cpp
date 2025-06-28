//
// Created by parsa on 6/8/25.
//
#include <ctime>
#include "Date.h"
#include <iostream>

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
    cout << "Enter year;\n";
    in >> p.year;
    cout << "Enter month:\n";
    in >> p.month;
    cout << "Enter day:\n";
    cin >> p.day;
    p.hour = localTime->tm_hour;
    p.minute = localTime->tm_min;
    return in;
}

ostream &operator<<(ostream &out, Date &p) {
    out << p.year << '/' << p.month << '/' << p.day << '\t' << p.hour << ':' << p.minute;
    return out;
}
