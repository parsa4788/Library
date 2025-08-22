//
// Created by parsa on 8/11/25.
//

#ifndef LIBRARY_LIBRARYMANAGER_H
#define LIBRARY_LIBRARYMANAGER_H

#include <iostream>

#include "Customer.h"

#include "Books.h"

#include "Date.h"

using namespace std;

class LibraryManager {
private:
    Customer customer;
    Books book;
    Date return_date;
    bool lended, reserve, get_back;
public:
    LibraryManager();

    friend ostream &operator<<(ostream &out, LibraryManager &x);

    void Lend_save(Books b, Customer c, Date d);

    void Get_back();

    bool check_lending(Customer c, Books b);

    bool late_return();

    void reserve_save(Books b, Customer c);

    void print_user_transaction(Customer c);

};


#endif //LIBRARY_LIBRARYMANAGER_H
