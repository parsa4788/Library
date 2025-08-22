//
// Created by parsa on 8/11/25.
//

#include "LibraryManager.h"
#include <iostream>
#include "Customer.h"
#include "Books.h"

using namespace std;

LibraryManager::LibraryManager() {
    reserve = false;
    lended = false;
    get_back = false;
}

ostream &operator<<(ostream &out, LibraryManager &x) {
    Date now;
    if (x.lended) {
        cout << "------------------------\nLending\n";
        cout << x.customer << "\n" << x.book << "\n" << "return date: " << x.return_date;
    } else if (x.reserve) {
        cout << "------------------------\nReserving\n";
        cout << x.customer << "\n" << x.book << "\n" << now;
    } else if (x.get_back) {
        cout << "\n------------------------\nGetting back\n";
        cout << x.customer << "\n" << x.book << "\n" << "Date: " << now;
    }
    return out;
}

void LibraryManager::Lend_save(Books b, Customer c, Date d) {
    book = b;
    customer = c;
    return_date = d;
    lended = true;
}

bool LibraryManager::check_lending(Customer c, Books b) {
    if (c.get_usrnum() == this->customer.get_usrnum() && b.get_booknum() == this->book.get_booknum() && lended
            )
        return true;
    else
        return false;
}

void LibraryManager::Get_back() {
    Date now;
    lended = false;
    get_back = true;
    cout << "Transaction saved successfully.\n";
    if (now > return_date) {
        cout << "The book was returned ( " << now - return_date << " days ) late.\n";
    } else {
        cout << "The book was returned ( " << return_date - now << " days ) sooner.\n";
    }
}

bool LibraryManager::late_return() {
    Date now;
    if (return_date < now && this->book.is_lended())
        return true;
    else
        return false;
}

void LibraryManager::reserve_save(Books b, Customer c) {
    Date d;
    return_date = d;
    reserve = true;
    lended = false;
    book = b;
    customer = c;
}

void LibraryManager::print_user_transaction(Customer c) {
    if (c.get_usrnum() == this->customer.get_usrnum() && lended) {
        cout << this << endl;
    }
}
