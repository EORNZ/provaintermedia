#include "BookShelf.h"
using namespace std;

class Invalid {};

BookShelf::BookShelf(int dim){
    if(dim<=0){
        throw Invalid();
    }
    size = dim;
    buffer_size = dim*2;
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

BookShelf::BookShelf(initializer_list<Book> lst){
    size = lst.size();
    buffer_size = lst.size();
    elem = new Book[size];
    copy(lst.begin(),lst.end(),elem);
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
    return elem[i];
}

Book& BookShelf::operator[](int i) {
    return elem[i];
}

BookShelf BookShelf::operator=(const BookShelf& m){
    BookShelf c = m;
    return c;
}

int BookShelf::get_buffer_size() const {
    return buffer_size;
}

int BookShelf::get_size() const {
    return size;
}

Book& BookShelf::at(int index){
    if(index<0 || index>=size){
        throw Invalid();
    }
    return elem[index];
}

Book BookShelf::at(int index) const{
    if(index<0 || index>=size){
        throw Invalid();
    }
    return elem[index];
}

void BookShelf::push_back(Book e){
    if(size==buffer_size){
        reserve(buffer_size*2);
    }
    elem[size] = e;
    size++;
}

Book BookShelf::pop_back(){
    Book e = elem[size-1];
    size--;
    return e;
}

void BookShelf::reserve(int n){
    if(n>buffer_size){
        buffer_size = n;
        Book* p = new Book[n];
        copy(elem,elem+size,p);
        delete[] elem;
        elem = p;
    }
}

ostream& operator<<(std::ostream& os, const BookShelf& b){
    string s;
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