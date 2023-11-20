#include "Book.h"
class InvalidBook{};
class InPrestito{};

Book::Book(std::string nome, std::string cognome, std::string titolo, std::string isbn){
    if(isbn.length()!=13){
        throw InvalidBook();
    }
    this->nome = nome;
    this->cognome = cognome;
    this->titolo = titolo;
    this->isbn = isbn;
    this->data = Date();
    this->stato = true; //è disponibile
}

Book::Book(std::string nome, std::string cognome, std::string titolo, std::string isbn, Date data){
    if(isbn.length()!=13){
        throw InvalidBook();
    }
    this->nome = nome;
    this->cognome = cognome;
    this->titolo = titolo;
    this->isbn = isbn;
    this->data = data;
    this->stato = true;
}

Book::Book(const Book& b){
    this->nome = b.nome;
    this->cognome = b.cognome;
    this->titolo = b.titolo;
    this->isbn = b.isbn;
    this->data = b.data;
    this->stato = b.stato;
}

/*Book::Book(){
    this->nome = "";
    this->cognome = "";
    this->titolo = "";
    this->isbn = "";
    this->data = Date();
    this->stato = true;
}*/

std::string Book::getIsbn() const{
    return isbn;
}

std::string Book::getTitolo() const{
    return titolo;
}

std::string Book::getNome() const{
    return nome;
}

std::string Book::getCognome() const{
    return cognome;
}

Date Book::getData() const{
    return data;
}

bool Book::getStato() const{
    return stato;
}

bool Book::operator==(const Book &b) const {
    if(this->isbn == b.isbn){
        return true;
    }
    return false;
}

bool Book::operator!=(const Book &b) const {
    return !operator==(b);
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
    std::string s;
    if(b.getStato()){
        s = "Disponibile";
    }
    else{
        s = "In prestito";
    }
    return os << b.getNome() << "\n" << b.getCognome() << "\n" << b.getTitolo() << "\n" << b.getIsbn() << "\n" << b.getData() << "\n" << s << "\n";
}

void Book::prendi(){
    if(stato == false){
        throw InPrestito();
    }
    stato = false;
}

void Book::restituisci(){
    stato = true;
}

std::string Book::toString() {
    std::string s;
    if(stato){
        s = "Disponibile";
    }
    else{
        s = "In prestito";
    }
    return nome + ", " + cognome + ", " + titolo + ", " + isbn + ", " + data.toString() + ", " + s + "\n";
}
