#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H
#include <iostream>
using namespace std;
class Date {
private:
    int year, month, day, hour, minute;
public:
    Date();
    friend istream &operator>>(istream &in, Date &p);
    friend ostream  &operator<<(ostream &out, Date &p);
};
#endif
