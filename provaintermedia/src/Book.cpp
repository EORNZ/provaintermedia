#include "../include/Book.h"

//costruttori
Book::Book() {
    this->nome = "";
    this->cognome = "";
    this->titolo = "";
    this->isbn = "";
    this->data = Date();
    this->stato = false;
}

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

Book::Book(std::string nome, std::string cognome, std::string titolo, std::string isbn, int gg, int mm, int aaaa) {
    if(isbn.length()!=13){
        throw InvalidBook();
    }
    this->nome = nome;
    this->cognome = cognome;
    this->titolo = titolo;
    this->isbn = isbn;
    this->data = Date(gg,mm,aaaa);
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

//overloading operatori
bool Book::operator==(const Book &b) const {
    if(this->isbn == b.isbn){
        return true;
    }
    return false;
}

bool Book::operator!=(const Book &b) const {
    return !operator==(b);
}

//funzioni membro
void Book::prendi(){
    if(stato == false){
        throw InPrestito();
    }
    stato = false;
}

void Book::restituisci(){
    if(!stato){
        stato = true;
    }
}

//ausiliari
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

//toString
std::string Book::toString() const {
    std::string s;
    if(stato){
        s = "Disponibile";
    }
    else {
        s = "In prestito";
    }
    return nome + ", " + cognome + ", " + titolo + ", " + isbn + ", " + data.toString() + ", " + s;
}

//ostream
std::ostream& operator<<(std::ostream& os, const Book& b) {
    std::string s;
    if(b.getStato()){
        s = "Disponibile";
    }
    else{
        s = "In prestito";
    }
    return os << b.getNome() << ", " << b.getCognome() << ", " << b.getTitolo() << ", " << b.getIsbn() << ", " << b.getData() << ", " << s;
}





