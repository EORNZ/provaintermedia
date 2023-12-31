#ifndef PROVAINTERMEDIA_BOOKSHELF_H
#define PROVAINTERMEDIA_BOOKSHELF_H
#include <iostream>
#include <initializer_list>
#include "Book.h"

class Invalid {};
class OutOfBounds{};
class Empty{};

class BookShelf{

public:
    //costruttori
    BookShelf();
    BookShelf(int);
    BookShelf(const BookShelf&);
    BookShelf(std::initializer_list<Book>);
    //distruttore
    ~BookShelf();

    //overloading operatori
    Book operator[](int) const;
    Book& operator[](int);
    BookShelf& operator=(const BookShelf&);
    
    //void prendi_libro(const Book&);
    //void restituisci_libro(const Book&);

    //ausiliari
    int getBufferSize() const;
    int getSize() const;
    bool isValid(int index) const;
    bool isEmpty() const;

    Book& at(int);
    Book at(int) const;
    void push_back(const Book&);
    Book pop_back();
    void reserve(int);
    
    //tostring
    std::string toString() const;

private:
    Book *elem;
    int size;
    int buffer_size;
};

//ostream
std::ostream& operator<<(std::ostream&, const BookShelf&);
#endif //PROVAINTERMEDIA_BOOKSHELF_H
