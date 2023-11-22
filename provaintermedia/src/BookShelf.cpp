#include "../include/BookShelf.h"

//costruttori
BookShelf::BookShelf() {
    buffer_size=0;
    size=0;
    elem= nullptr;
}

BookShelf::BookShelf(int dim){
    if(dim<=0){
        throw Invalid();
    }
    size = 0;
    buffer_size = dim*2;
    elem = new Book[dim];

}

BookShelf::BookShelf(const BookShelf& m){
    size = m.size;
    buffer_size = m.buffer_size;
    elem = new Book[m.size];
    for(int i=0; i<size;i++){
        elem[i]=m[i];
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

BookShelf& BookShelf::operator=(const BookShelf& s){
    Book *np = new Book[s.size];
    std::copy(s.elem, s.elem + size, np);
    delete[] this->elem;
    this->elem = np;
    this->size = s.size;
    return *this;
}

//funzioni membro
Book& BookShelf::at(int i){
    if (!is_valid(i)){
        throw OutOfBounds();
    }
    return elem[i];
}

Book BookShelf::at(int i) const {
    if (!is_valid(i)) {
        throw OutOfBounds();
    }
    return elem[i];
}

void BookShelf::push_back(const Book e){
    if (elem == nullptr){
        buffer_size = 1;
        elem = new Book[buffer_size];
    }
    else if (size == buffer_size){
        reserve(buffer_size*2);
    }
    elem[size] = e;
    size++;
}

void BookShelf::reserve(int n){
    if (n>buffer_size){
        buffer_size = n;
        Book *np = new Book[buffer_size];
        std::copy(this->elem, this->elem + size, np);
        delete[] this->elem;
        this->elem = np;
    }else{
        throw Invalid();
    }
}

Book BookShelf::pop_back(){
    if (!is_empty()){
        throw Empty();
    }
    Book e = elem[size-1];
    size--;
    return e;
}

//ausiliari
int BookShelf::getBufferSize() const {
    return buffer_size;
}

int BookShelf::getSize() const {
    return size;
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

bool BookShelf::is_valid(int index) const
{
    return (index >= 0 && index < size);
}

bool BookShelf::is_empty()
{
    return size != 0;
}

//ostream
std::ostream& operator<<(std::ostream& os, const BookShelf& b){
    std::string s;
    for (int i = 0; i < b.getSize(); i++) {
        if(i<b.getSize()-1){
            s = s + b[i].toString() + "\n";
        }
        else{
            s = s + b[i].toString();
        }
    }
    return os << s;
}