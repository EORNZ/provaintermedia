#ifndef PROGETTO_BOOK_H
#define PROGETTO_BOOK_H
#include <iostream>
#include "Date.h"

class Book{
private:
    std::string isbn;
    std::string titolo;
    std::string nome;
    std::string cognome;
    Date data;
    bool stato; //true se disponibile, false se in prestito

public:
    Book(std::string, std::string, std::string, std::string);
    Book(std::string, std::string, std::string, std::string, Date);
    Book(const Book&);
    //Book();
    std::string getIsbn() const;
    std::string getTitolo() const;
    std::string getNome() const;
    std::string getCognome() const;
    Date getData() const;
    bool getStato() const;
    bool operator==(const Book&) const;
    bool operator!=(const Book&) const;
    void prendi();
    void restituisci();
    std::string toString();
};

std::ostream& operator<<(std::ostream&, const Book&);
#endif //PROGETTO_BOOK_H