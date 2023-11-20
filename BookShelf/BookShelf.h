#ifndef PROGETTO_BOOKSHELF_H
#define PROGETTO_BOOKSHELF_H
#include <iostream>
#include <initializer_list>
#include "Book.h"
using namespace std;

class BookShelf{
private:
    Book *elem;
    int size;
    int buffer_size;

public:
    BookShelf(int);
    BookShelf(const BookShelf&);
    BookShelf(initializer_list<Book>);
    ~BookShelf();
    BookShelf operator=(const BookShelf&);
    Book operator[](int) const;
    Book& operator[](int);
    int get_size() const;
    int get_buffer_size() const;
    Book& at(int);
    Book at(int) const;
    void push_back(Book);
    Book pop_back();
    void reserve(int);
};

std::ostream& operator<<(std::ostream&, const BookShelf&);
#endif //PROGETTO_BOOKSHELF_H