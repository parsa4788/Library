//
// Created by parsa on 8/11/25.
//

#include "LibraryManager.h"
#include <iostream>
#include "Customer.h"
#include "Books.h"

using namespace std;

ostream &operator<<(ostream &out, LibraryManager &x) {
    if (x.operation) {
        cout << "------------------------\nLending\n";
        cout << x.customer << "\n" << x.book << "\n" << "form: " << x.now << " to " << x.return_date
             << "\n------------------------";
    } else {
        cout << "------------------------\nReserving\n";
        cout << x.customer << "\n" << x.book << "\n" << x.now << "\n------------------------\n";
    }
    return out;
}

void LibraryManager::Lend_save(Books b, Customer c, Date d) {
    book = b;
    customer = c;
    return_date = d;
    operation = true;
}
