//
// Created by parsa on 6/8/25.
//
#ifndef LIBRARY_CUSTOMER_H
#define LIBRARY_CUSTOMER_H

#include <iostream>
#include <cstring>

using namespace std;

#include "Date.h"

class Customer {
private:
    char name[21], family[21], father[21], Phone_number[12];
    Date dob;
    int user_num, borrow_num;
    bool removed;
public:
    Customer();

    friend istream &operator>>(istream &in, Customer &c);

    friend ostream &operator<<(ostream &out, Customer &c);

    void set_user_num(int x);

    void Remove();

    bool check_user_num();

    void Edit();

    int get_usrnum();

    bool check_pass(char p[12]);

};


#endif //LIBRARY_CUSTOMER_H
