#include <iostream>
#include "include/Book.h"
#include "include/BookShelf.h"

using namespace std;

int main() {

    cout<<"\n-------BOOKSHELF-------";
    Date d1= *new Date(10,12,2023);

    Book mybook("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1", Date(10,9,2023));
    mybook.prendi();

    Book mybook2("Anna", "Premoli", "Facciamo finta che mi ami", "667-432-178-4",d1);

    Book mybook3("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4",6,8,1997);

    Book mybook4("Alessia", "Gazzola", "Le ossa della principessa", "135-999-087-7");


    BookShelf shelf;

    shelf.push_back(mybook);
    shelf.push_back(mybook2);
    shelf.push_back(mybook3);
    shelf.push_back(mybook4);

    cout<< "\n"<<shelf;


    cout<<"\n---------Elimino l'ultimo elemento--------";
    shelf.pop_back();
    cout<< "\n"<<shelf;

    cout<<"\n---------Controllo se mybook4 e mybook2 sono uguali--------";

    if(mybook4.operator==(mybook2)){
        cout<<"\ni due libri sono uguali";
    }else{
        cout<<"\ni due libri non sono uguali";
    }
    return 0;
}