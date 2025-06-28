//
// Created by parsa on 6/8/25.
//
#include <iostream>
#include <string.h>

using namespace std;

#include "Books.h"

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
    return in;
}

ostream &operator<<(ostream &out, Books &b) {
    out << b.name << '\t';
    for (int i = 0; i < b.author_number; i++) {
        out << b.authors[i] << '\t';
    }
    out << b.isbn << '\t' << b.book_number << '\t' << b.borrowed_number;
    return out;
}

void Books::set_book_number(long long number) {
    book_number = number;
}
