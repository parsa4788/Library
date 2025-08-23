//
// Created by parsa on 6/8/25.
//
#include <iostream>
#include "Customer.h"

using namespace std;

Customer::Customer() {
    borrow_num = 0;
    removed = false;
}

istream &operator>>(istream &in, Customer &c) {
    cout << "Enter name:\n";
    in >> c.name;
    cout << "Enter family name:\n";
    in >> c.family;
    cout << "Enter father's name:\n";
    in >> c.father;
    cout << "Enter date of birth:\n";
    cin >> c.dob;
    cout << "Enter phone number:\n";
    cin >> c.Phone_number;
    return in;
}

ostream &operator<<(ostream &out, Customer &c) {
    out << c.name << ' ' << c.family << '\t' << c.father << '\t' << c.dob << '\t' << c.user_num << '\t'
        << c.Phone_number << '\t' << "borrow number: " << c.borrow_num;
    return out;
}

void Customer::set_user_num(int x) {
    user_num = x;
}

void Customer::Remove() {
    removed = true;
}

bool Customer::check_user_num() {
    return removed;
}

int Customer::get_usrnum() {
    return user_num;
}

void Customer::Edit() {
    int choice;
    while (true) {
        cout << "What do you want to edit?\n";
        cout << "1. Name\n";
        cout << "2. Family name\n";
        cout << "3. Father name\n";
        cout << " 4. Date of birth\n";
        cout << "0. EXit\n";
        cin >> choice;
        switch (choice) {
            case 0:
                return;
            case 1:
                cout << "Current: " << name << "\nEnter new:\n";
                cin >> name;
                break;
            case 2:
                cout << "Current: " << family << "\nEnter new:\n";
                cin >> family;
                break;
            case 3:
                cout << "Current: " << father << "\n Enter new:\n";
                cin >> father;
                break;
            case 4:
                cout << "Current: " << dob << "\nEnter new:\n";
                cin >> dob;
                break;
            default:
                return;

        }
    }

}

bool Customer::check_pass(char pass[12]) {
    if (strcmp(pass, Phone_number) == 0)
        return true;
    else
        return false;
}

void Customer::print_name() {
    cout << name << " " << family;
}

void Customer::Lend() {
    borrow_num++;
}