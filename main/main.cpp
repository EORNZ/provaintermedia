#include <iostream>
#include "Book.h"
#include "BookShelf.h"

using namespace std;

int main() {
    Book mybook("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4");
    mybook.prendi();

    BookShelf shelf(10);
    shelf.push_back(mybook);

    //shelf.pop_back();
    cout<<shelf<<endl;
    return 0;
}