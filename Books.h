//
// Created by parsa on 6/8/25.
//

#ifndef LIBRARY_BOOKS_H
#define LIBRARY_BOOKS_H

#include <iostream>

using namespace std;

class Books {
public:

    void set_book_number(long long number);

    friend istream &operator>>(istream &in, Books &b);

    friend ostream &operator<<(ostream &out, Books &b);

    void Search_book_name(string x, bool &b);

    void Search_book_author(string x, bool &b);

    void Search_book_ISBN(string isbn, bool &b);

    bool removed();

    void delete_book();

    void Edit();

private:
    char name[31], authors[5][21], isbn[14];
    int author_number, book_number, borrowed_number;
    bool remove;

};


#endif //LIBRARY_BOOKS_H
