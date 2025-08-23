//
// Created by parsa on 6/8/25.
//
#include <iostream>
#include <string.h>
#include <string>
#include"Customer.h"

using namespace std;

#include "Books.h"

Books::Books() {
    lend = false;
    reserve = false;
    borrowed_number = 0;
    author_number = 0;
    remove = false;
}

istream &operator>>(istream &in, Books &b) {
    int i;
    cout << "Enter name of the book:\n";
    in.ignore();
    in.get(b.name, 30);
    cout << "Enter author:\n";
    in.ignore();
    in.get(b.authors[0], 20);
    for (i = 1; strcmp(b.authors[i - 1], "0") != 0; i++) {
        cout << "Enter next author:\nIf there is none left pleas enter 0.\n";
        in.ignore();
        in.get(b.authors[i], 20);
    }
    b.author_number = i - 1;
    cout << "Enter ISBN number:\n";
    in >> b.isbn;
    b.remove = false;
    b.lend = false;
    b.reserve = false;
    return in;
}

ostream &operator<<(ostream &out, Books &b) {
    out << b.name << '\t';
    for (int i = 0; i < b.author_number; i++) {
        out << b.authors[i] << '\t';
    }
    out << b.isbn << '\t' << b.book_number << '\t' << b.borrowed_number << "\t" << "author number: " << b.author_number;
    return out;
}

void Books::set_book_number(long long number) {
    book_number = number;
}

void Books::Search_book_name(string x, bool &check) {
    string title = name;
    if (title == x) {
        check = false;
        cout << *this << "\n";
    }
}

void Books::Search_book_author(string x, bool &check) {
    for (int i = 0; i < author_number; i++) {
        string Author = authors[i];
        if (Author == x) {
            check = false;
            cout << *this << "\n";
            return;
        }
    }
}

void Books::Search_book_ISBN(string x, bool &check) {
    if (isbn == x) {
        check = false;
        cout << *this << "\n";
    }
}

bool Books::removed() {
    return remove;
}

void Books::delete_book() {
    remove = true;
}

void Books::Edit() {
    int choice;
    char c;
    while (true) {
        cout << "What do you want to edit?\n";
        cout << "1. Title.\n";
        cout << "2. Author.\n";
        cout << "3. ISBN number.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Current: " << name << "\nEnter new:\n";
                cin >> name;
                break;
            case 2:
                for (int i = 0; i < author_number; i++) {
                    cout << "Current: " << authors[i] << "\nDo you want to edit this author? [Y/N]\n";
                    cin >> c;
                    if (c == 'y' || c == 'Y') {
                        cout << "Enter new:\n";
                        cin.ignore();
                        cin.get(authors[i], 20);
                    } else
                        return;
                }
                break;
            case 3:
                cout << "Current: " << isbn << "\nEnter new:\n";
                cin >> isbn;
                break;
            case 0:
                return;

        }
    }
}

void Books::Lend() {
    lend = true;
    borrowed_number++;
}

bool Books::is_lended() {
    return lend;
}

int Books::get_booknum() {
    return book_number;
}

void Books::get_back() {
    lend = false;
    reserve = false;
}

void Books::book_reserve() {
    reserve = true;
}

int Books::get_borrow_num() {
    return borrowed_number;
}

bool Books::is_reserved() {
    return reserve;
}