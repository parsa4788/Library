#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    fstream f;
    f.open("MyBooks.dat", ios::in | ios::binary);
    if(!f.is_open())
    {
        cout<<"Error opening file.\n";
        return 0;
    }
    cout<<"File opened successfuly.\n";
    
    return 0;
}