#include <iostream>


#include "Books.h"
#include "Customer.h"
#include <string>
#include <fstream>
#include "LibraryManager.h"

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
    f.close();
}

bool valid_book_num(int number) {
    Books book;
    int pos;
    fstream f;
    f.open("MyBooks.dat", ios::binary | ios::in);
    if (!f.is_open()) {
        cout << "Error opening file.\n";
        return false;
    }
    pos = (number - 4041234) * sizeof(Books);
    f.seekp(pos, ios::beg);
    f.read((char *) &book, sizeof(Books));
    f.close();
    if (book.removed())
        return false;
    unsigned long int max = (file_size("MyBooks.dat") / sizeof(Books)) + 4041234;
    if (number < 4041234 || number >= max)
        return false;
    return true;
}

void sub_menu_search_books() {
    bool check;
    string x;
    Books b;
    fstream f;
    int choice;
    int number;
    while (true) {
        cout << "1. By book name.\n";
        cout << "2. By author name.\n";
        cout << "3. By ISBN number.\n";
        cout << "4. By book number.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Please enter book title:\n";
                cin.ignore();
                getline(cin, x);
                check = true;
                f.open("MyBooks.dat", ios::in | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                f.read((char *) &b, sizeof(Books));
                while (!f.eof()) {
                    b.Search_book_name(x, check);
                    f.read((char *) &b, sizeof(Books));
                }
                if (check)
                    cout << "Nothing was found!\n";
                f.close();
                break;
            case 2:
                cout << "Please enter book author:\n";
                cin.ignore();
                getline(cin, x);
                check = true;
                f.open("MyBooks.dat", ios::in | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                f.read((char *) &b, sizeof(Books));
                while (!f.eof()) {
                    b.Search_book_author(x, check);
                    f.read((char *) &b, sizeof(Books));
                }
                if (check)
                    cout << "Nothing was found!\n";
                f.close();
                break;
            case 3:
                cout << "Please enter book ISBN number.\n";
                cin >> x;
                check = true;
                f.open("MyBooks.dat", ios::in | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                f.read((char *) &b, sizeof(Books));
                while (!f.eof()) {
                    b.Search_book_ISBN(x, check);
                    if (!check)
                        break;
                    f.read((char *) &b, sizeof(Books));
                }
                if (check)
                    cout << "Nothing was found!\n";
                f.close();
                break;
            case 4 :
                cout << "Please enter book number.\n";
                cin >> number;
                if (!valid_book_num(number)) {
                    cout << "Invalid book number.\nPlease try again.\n";
                    return;
                }
                number = (number - 4041234) * sizeof(Books);
                f.open("MyBooks.dat", ios::in | ios::binary);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                f.seekp(number, ios::beg);
                f.read((char *) &b, sizeof(Books));
                cout << b;
                f.close();
                break;
            case 0:
                return;
            default:
                cout << "Wrong choice!\nTry again.\n";
                break;


        }
    }
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
                    if (!b.removed())
                        cout << b << endl;
                    x.read((char *) &b, sizeof(Books));
                }
                x.close();
                break;
            case 2:
                sub_menu_search_books();
                break;
            default:
                cout << "Wrong choice!\nPlease try again.\n";

        }
    }
}

void sub_menu_3() {
    int choice, num;
    char c;
    bool check = true;
    int pos;
    fstream f;
    Books book;
    while (true) {
        cout << "1. Delete book.\n";
        cout << "2. Edit book information\n";
        cout << "3. Search for books.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Please enter book number:\n";
                cin >> num;
                if (!valid_book_num(num))
                    cout << "Such book number does not exist.\n";
                else {
                    pos = (num - 4041234) * sizeof(Books);
                    f.open("MyBooks.dat", ios::binary | ios::in | ios::out);
                    if (!f.is_open()) {
                        cout << "Error opening file.\n";
                        return;
                    }
                    f.seekp(pos, ios::beg);
                    f.read((char *) &book, sizeof(Books));
                    while (check) {
                        cout << book;
                        cout << "\nAre you sure you want to delete this book? [Y/N]\n";
                        cin >> c;
                        if (c == 'Y' || c == 'y')
                            check = false;
                        else if (c == 'N' || c == 'n') {
                            f.close();
                            sub_menu_3();
                        } else {
                            f.close();
                            cout << "Wrong choice!\nPlease try again\n";
                        }
                    }
                    if (f.bad()) {
                        cout << "Error reading file.\n";
                        return;
                    }
                    book.delete_book();
                    f.seekp(pos, ios::beg);
                    f.write((char *) &book, sizeof(Books));
                    f.close();
                    cout << "Book deleted successfully.\n";
                }
                break;
            case 2:
                cout << "Please enter book number:\n";
                cin >> num;
                if (!valid_book_num(num))
                    cout << "Such book number does not exist.\n";
                else {
                    pos = (num - 4041234) * sizeof(Books);
                    f.open("MyBooks.dat", ios::in | ios::out | ios::binary);
                    if (!f.is_open()) {
                        cout << "Error opening file.\n";
                        return;
                    }
                    f.seekp(pos, ios::beg);
                    f.read((char *) &book, sizeof(Books));
                    if (f.bad()) {
                        cout << "Error reading file.\n";
                        return;
                    }
                    book.Edit();
                    f.seekp(pos, ios::beg);
                    f.write((char *) &book, sizeof(Books));
                    if (f.bad()) {
                        cout << "Error writing file.\n";
                        return;
                    }
                    f.close();
                    cout << "Book edited successfully.\n";
                }
                break;
            case 3:
                sub_menu_search_books();
                break;
            case 0:
                return;
            default:
                cout << "Wrong choice!\nPlease try again.\n";

        }
    }
}

void sub_menu_5() {
    Customer customer;
    fstream f;
    int choice, number;
    size_t pos;
    char c;
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
                cout << customer << "\nAre you sure you wnat to remove this member? [Y/N]\n";
                cin >> c;
                if (c != 'y' && c != 'Y') {
                    f.close();
                    return;
                }
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
    int choice, num;
    size_t pos;
    Customer customer;
    Books book;
    fstream f;
    LibraryManager l;
    while (true) {
        cout << "Enter member's membership number:\n";
        cin >> num;
        if (!valid_user_number(num)) {
            cout << "Invalid membership number.\n";
            return;
        }
        f.open("Customer.dat", ios::binary | ios::in);
        if (!f.is_open()) {
            cout << "Error opening file.\n";
            return;
        }
        pos = (num - 18937648) * sizeof(Customer);
        f.seekp(pos, ios::beg);
        f.read((char *) &customer, sizeof(Customer));
        f.close();
        cout << customer << endl;
        cout << "1. Lend\n";
        cout << "2. Get back\n";
        cout << "3. Reserve\n";
        cout << "0. Exit\n";
        cin >> choice;
        switch (choice) {
            case 0:
                return;
            case 1:
                cout << "Enter book number:\n";
                cin >> num;
                if (!valid_book_num(num)) {
                    cout << "Invalid book number.\n";
                    return;
                }
                f.open("MyBooks.dat", ios::binary | ios::in | ios::out);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                pos = (num - 4041234) * sizeof(Books);
                f.seekp(pos, ios::beg);
                f.read((char *) &book, sizeof(Books));
                cout << book << endl;
                book.Lend(customer);
                f.seekp(pos, ios::beg);
                f.write((char *) &book, sizeof(Books));
                f.close();
                f.open("LibraryManager.dat", ios::out | ios::binary | ios::app);
                if (!f.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                l.Lend_save(book, customer);
                f.write((char *) &l, sizeof(LibraryManager));
                f.close();
                cout << "Book lending completed.\n";
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

void sub_menu_7() {
    int choice;
    while (true) {
        cout << "1. Books with late return.\n";
        cout << "2. Popular books.\n";
        cout << "3. Active members.\n";
        cout << "4. transactions.\n";
        cout << "0. EXit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                break;
            default:
                cout << "Wrong choice.\n";
        }
    }
}

void Admin_menu() {
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
                return;
            case '1':
                sub_menu_1();
                break;
            case '2':
                cin >> book;
                x.open("MyBooks.dat", ios::app | ios::binary);
                if (!x.is_open()) {
                    cout << "Error opening file.\n";
                    return;
                }
                book.set_book_number((file_size("MyBooks.dat") / sizeof(Books)) + 4041234);
                x.write((char *) &book, sizeof(Books));
                x.close();
                cout << "New book added.\n";
                break;
            case '3':
                sub_menu_3();
                break;
            case '4':
                break;
            case '5':
                sub_menu_5();
                break;
            case '6':
                sub_menu_6();
                break;
            case '7':
                break;
            default:
                cout << "Wrong choice!\n";
                return;
        }


    }

}

void Member_menu() {
    int choice;
    while (true) {
        cout << "1. Search books.\n";
        cout << "2. Get book.\n";
        cout << "3. Tamdid.\n";
        cout << "4. Show loaned books.\n";
        cout << "5. Show list of loaned books.\n";
        cout << "6. Reserve book.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                return;
            default:
                cout << "Wrong choice!\nPlease try again.\n";
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Admin\n";
        cout << "2. Member\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 1:
                Admin_menu();
                break;
            case 2:
                Member_menu();
                break;
            case 0:
                return 0;
            default:
                cout << "Wrong choice.\n";
        }
    }
}