#ifndef PROVAINTERMEDIA_BOOK_H
#define PROVAINTERMEDIA_BOOK_H
#include <iostream>
#include "Date.h"

class InvalidBook{};
class InPrestito{};

class Book{

public:
    //costruttori
    Book();
    Book(std::string, std::string, std::string, std::string);
    Book(std::string, std::string, std::string, std::string, Date);
    Book(std::string, std::string, std::string, std::string, int, int, int);
    Book(const Book&);

    //overloading operatori
    bool operator==(const Book&) const;
    bool operator!=(const Book&) const;

    //ausiliari
    std::string getIsbn() const;
    std::string getTitolo() const;
    std::string getNome() const;
    std::string getCognome() const;
    Date getData() const;
    bool getStato() const;

    void prendi();
    void restituisci();

    //tostring
    std::string toString() const;

private:
    std::string isbn;
    std::string titolo;
    std::string nome;
    std::string cognome;
    Date data;
    bool stato; //true se disponibile, false se in prestito
};

//ostream
std::ostream& operator<<(std::ostream&, const Book&);
#endif //PROVAINTERMEDIA_BOOK_H
