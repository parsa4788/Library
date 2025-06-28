#include <iostream>


#include "Books.h"
#include "Customer.h"
#include <string>
#include <fstream>

using namespace std;

long long file_size(const string &filename) {
    long long x;
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 0;
    }
    file.seekg(0, ios::end);
    x = file.tellg();
    file.close();
    return x;
}

bool valid_user_number(int num) {
    Customer c;
    long int p = (num - 18937648) * sizeof(Customer);
    if (p >= file_size("Customer.dat"))
        return false;
    else if (num < 18937648)
        return false;
    fstream f;
    f.open("Customer.dat", ios::in | ios::binary);
    if (!f.is_open()) {
        cout << "Error opening file.\n";
        return false;
    }
    f.seekp(p, ios::beg);
    f.read((char *) &c, sizeof(Customer));
    if (c.check_user_num())
        return false;
    else
        return true;
}

void sub_menu_1() {
    Books b;
    fstream x;
    int choice;
    while (true) {
        cout << "1. Print all books.\n";
        cout << "2. Search.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 0:
                return;
            case 1:
                x.open("MyBooks.dat", ios::in | ios::binary);
                if (!x.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                x.read((char *) &b, sizeof(Books));
                while (!x.eof()) {
                    cout << b << endl;
                    x.read((char *) &b, sizeof(Books));
                }
                x.close();
                break;
            case 2:
                break;

        }
    }
}

void sub_menu_5() {
    Customer customer;
    fstream f;
    int choice, number, pos;
    while (true) {
        cout << "1. Add new member.\n";
        cout << "2. Edit member.\n";
        cout << "3. Delete member.\n";
        cout << "4. Print all members.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 0:
                return;
            case 1:
                cin >> customer;
                f.open("Customer.dat", ios::app | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                customer.set_user_num((file_size("Customer.dat") / sizeof(Customer) + 18937648));
                f.write((char *) &customer, sizeof(Customer));
                f.close();
                cout << "New member added.\n";
                break;
            case 2:
                cout << "Enter member's membership number.\n";
                cin >> number;
                if (!valid_user_number(number)) {
                    cout << "Invalid membership number.\n";
                    break;
                }
                f.open("Customer.dat", ios::in | ios::out | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                pos = (number - 18937648) * sizeof(Customer);
                f.seekp(pos, ios::beg);
                f.read((char *) &customer, sizeof(Customer));
                if (f.bad()) {
                    cout << "Error reading file.\n";
                    f.close();
                    break;
                }
                customer.Edit();
                f.seekp(pos, ios::beg);

                f.seekp(pos, ios::beg);
                f.write((char *) &customer, sizeof(Customer));
                if (f.bad()) {
                    cout << "Error writing in file.\n";
                    f.close();
                    break;
                }
                f.close();
                cout << "member edited successfully.\n";
                break;
            case 3:
                cout << "Enter member's membership number.\n";
                cin >> number;
                if (!valid_user_number(number)) {
                    cout << "Invalid membership number.\n";
                    break;
                }
                f.open("Customer.dat", ios::in | ios::out | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                pos = (number - 18937648) * sizeof(Customer);
                f.seekp(pos, ios::beg);
                f.read((char *) &customer, sizeof(Customer));
                if (f.bad()) {
                    cout << "Error reading file.\n";
                    f.close();
                    break;
                }
                customer.Remove();
                f.seekp(pos, ios::beg);
                f.write((char *) &customer, sizeof(Customer));
                if (f.bad()) {
                    cout << "Error writing in file.\n";
                    f.close();
                    break;
                }
                f.close();
                cout << "Member removed successfully.\n";

                break;
            case 4:
                f.open("Customer.dat", ios::in | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                f.read((char *) &customer, sizeof(Customer));
                while (!f.eof()) {
                    if (!customer.check_user_num())
                        cout << customer;
                    f.read((char *) &customer, sizeof(Customer));
                }
                f.close();
                break;
            default:
                cout << "Wrong choice.\n";
                return;

        }
    }
}

void sub_menu_6() {
    int choice;
    while (true) {
        cout << "1. Lend\n";
        cout << "2. Get back\n";
        cout << "3. Reserve\n";
        cout << "0. Exit\n";
        cin >> choice;
        switch (choice) {
            case 0:
                return;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                return;
        }
    }
}

int main() {
    char choice;
    Books book;
    fstream x;
    while (true) {
        cout << "1. Show/look for books in library.\n";
        cout << "2. Add new book.\n";
        cout << "3. Delete, Edit, Search.\n";
        cout << "4. Show loaned books.\n";
        cout << "5. Add / Delete / Edit member:\n";
        cout << "6. Bookkeeping.\n";
        cout << "7. Reports.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case '0':
                return 0;
            case '1':
                sub_menu_1();
                break;
            case '2':
                cin >> book;
                x.open("MyBooks.dat", ios::app | ios::binary);
                if (!x.is_open()) {
                    cout << "Error opening file.\n";
                    return 0;
                }
                book.set_book_number((file_size("MyBooks.dat") / sizeof(Books)) + 4041234);
                x.write((char *) &book, sizeof(Books));
                x.close();
                cout << "New book added.\n";
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                sub_menu_5();
                break;
            case '6':
                sub_menu_6();
                break;
            default:
                cout << "Wrong choice!\n";
                return 0;
                break;
        }


    }

}