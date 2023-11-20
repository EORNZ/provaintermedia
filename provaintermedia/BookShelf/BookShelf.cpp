#include "BookShelf.h"

class Invalid {};
class OutOfBounds{};
class Empty{};

BookShelf::BookShelf() {
    buffer_size=0;
    size=0;
    elem= nullptr;
}

BookShelf::BookShelf(int dim){
    if(dim<=0){
        throw Invalid();
    }
    size = dim;
    buffer_size = dim;
    elem = new Book[dim];
    for(int i=0;i<dim;i++){
        elem[i]=Book();
    }
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
    /*
     oppure senza il copy:

     elem=new double[size];
     const double *p = lst.begin();
     for(int i=0; i<size;i++){
        elem[i] = *(p+i);
     }
     */
}

BookShelf::~BookShelf() {
    delete[] elem;
}

Book BookShelf::operator[](int i) const {
    if (!is_valid(i)){
        throw OutOfBounds();
    }
    return elem[i];
}

Book& BookShelf::operator[](int i) {
    if (!is_valid(i)){
        throw OutOfBounds();
    }
    return elem[i];
}

BookShelf BookShelf::operator=(const BookShelf& s){
    Book *np = new Book[s.size];
    std::copy(s.elem, s.elem + size, np);
    delete[] this->elem;
    this->elem = np;
    this->size = s.size;
    return *this;
}

int BookShelf::get_buffer_size() const {
    return buffer_size;
}

int BookShelf::get_size() const {
    return size;
}

Book& BookShelf::at(int i){
    if (!is_valid(i)){
        throw OutOfBounds();
    }
    return elem[i];
}

Book BookShelf::at(int i) const{
    if (!is_valid(i)){
        throw OutOfBounds();
    }
    return elem[i];
}

void BookShelf::set_at(int i, Book e) const{
    if (!is_valid(i)){
        throw OutOfBounds();
    }
    elem[i] = e;
}

void BookShelf::set_at(int i, Book e){
    if (!is_valid(i)){
        throw OutOfBounds();
    }
    elem[i] = e;
}

void BookShelf::push_back(const Book e){

    if (elem == nullptr){
        buffer_size = 1;
        elem = new Book[buffer_size];
    }
    else if (size == buffer_size)
        reserve(1);

    elem[size] = e;
    ++size;
}

void BookShelf::reserve(int n){
    if (n < 0)
        throw Invalid();
    buffer_size += n;
    Book *np = new Book[buffer_size];
    std::copy(this->elem, this->elem + size, np);
    delete[] this->elem;
    this->elem = np;
}

Book BookShelf::pop_back(){
    if (!is_empty()){
        throw Empty();
    }
    Book e = elem[size-1];
    --size;
    return e;
}

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


std::ostream& operator<<(std::ostream& os, const BookShelf& b){
    std::string s;
    for (int i = 0; i < b.get_size(); i++) {
        if(i<b.get_size()-1){
            s = s + b[i].toString() + ", ";
        }
        else{
            s = s + b[i].toString() + "\n";
        }
    }
    return os << s;
}