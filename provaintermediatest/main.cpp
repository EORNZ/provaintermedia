#include <iostream>
#include "include/Book.h"
#include "include/BookShelf.h"

using namespace std;

int main() {
    Book mybook("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4",6,8,1997);
    mybook.prendi();

    BookShelf shelf;

    shelf.push_back(mybook);
    shelf.reserve(3);
    cout<< shelf <<endl;

    return 0;
}