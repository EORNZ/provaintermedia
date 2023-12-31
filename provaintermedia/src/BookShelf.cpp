#include "../include/BookShelf.h"

//costruttori
BookShelf::BookShelf() {
    buffer_size=0;
    size=0;
    elem=nullptr;
}

BookShelf::BookShelf(int dim){
    if(dim<=0){
        throw Invalid();
    }
    size = 0;
    buffer_size = dim;
    elem = new Book[dim];
}

BookShelf::BookShelf(const BookShelf& b){
    size = b.size;
    buffer_size = b.buffer_size;
    elem = new Book[b.size];
    for(int i=0; i<size;i++){
        elem[i]=b[i];
    }
}

BookShelf::BookShelf(std::initializer_list<Book> lst){
    size = lst.size();
    buffer_size = lst.size();
    elem = new Book[size];
    std::copy(lst.begin(),lst.end(),elem);
}
//distruttore
BookShelf::~BookShelf() {
    delete[] elem;
}

//overloading operatori
Book BookShelf::operator[](int i) const {
    return elem[i];
}

Book& BookShelf::operator[](int i) {
    return elem[i];
}

BookShelf& BookShelf::operator=(const BookShelf& b){
    Book *np = new Book[b.size];
    std::copy(b.elem, b.elem + b.size, np);
    delete[] elem;
    elem = np;
    size = b.size;
    buffer_size = b.buffer_size;
    return *this;
}

//ausiliari
int BookShelf::getBufferSize() const {
    return buffer_size;
}

int BookShelf::getSize() const {
    return size;
}

bool BookShelf::isValid(int index) const{
    return (index >= 0 && index < size);
}

bool BookShelf::isEmpty() const{
    return size==0;
}

//altre
/*void BookShelf::prendi_libro(const Book& b){
    for (int i = 0; i < size; i++) {
        if(b==elem[i] && elem[i].getStato()){
            elem[i].prendi();
            return;
        }
    }
    std::cout<< "nessun [ "<< b <<" ] disponibile\n"; //da sistemare
}

void BookShelf::restituisci_libro(const Book& b){
    for (int i = 0; i < size; i++) {
        if(b==elem[i] && !elem[i].getStato()){
            elem[i].restituisci();
            return;
        }
    }
    std::cout<<"[ "<< b <<" ] gia' restituito\n"; //da sistemare
}*/

Book& BookShelf::at(int i){
    if (!isValid(i)){
        throw OutOfBounds();
    }
    return elem[i];
}

Book BookShelf::at(int i) const {
    if (!isValid(i)) {
        throw OutOfBounds();
    }
    return elem[i];
}

void BookShelf::reserve(int n){
    if (n > buffer_size){
        buffer_size = n;
        Book *np = new Book[buffer_size];
        std::copy(elem, elem + size, np);
        delete[] elem;
        elem = np;
    }
}

void BookShelf::push_back(const Book& e){
    if (elem == nullptr){
        buffer_size = 1;
        elem = new Book[buffer_size];
    }
    else if (size == buffer_size){
        reserve(buffer_size * 2);
    }
    elem[size] = e;
    size++;
}

Book BookShelf::pop_back(){
    if (isEmpty()){
        throw Empty();
    }
    Book e = elem[size-1];
    size--;
    return e;
}

//toString
std::string BookShelf::toString() const{
    std::string s = "[";
    for (int i = 0; i < size; i++)
    {
        s += elem[i].toString();
        if (i < size - 1)
            s += ", ";
    }
    s += "]";
    return s;
}

//ostream
std::ostream& operator<<(std::ostream& os, const BookShelf& b){
    std::string s;
    for (int i = 0; i < b.getSize(); i++) {
        s+="[ "+ std::to_string(i+1) + ") ";
        if(i<b.getSize()-1){
            s = s + b[i].toString() + " ] \n";
        }
        else{
            s = s + b[i].toString() + " ]";
        }
    }
    return os << s;
}
