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
    Date return_date,now;
    bool operation;
public:
    friend ostream &operator<<(ostream &out, LibraryManager &x);

    void Lend_save(Books b,Customer c,Date d);

};


#endif //LIBRARY_LIBRARYMANAGER_H
