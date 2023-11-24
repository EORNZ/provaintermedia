#include <iostream>
#include "include/Book.h"
#include "include/BookShelf.h"

using namespace std;

int main() {
    Date d1 = Date(10,12,2023);
    Book mybook12;
    BookShelf shelf55 = { mybook12 };
    cout<<shelf55;
    cout<<"------------------------------------------------------------------------";
    Book mybook1("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1",10,9,2023);
    mybook1.prendi();

    Book mybook2("Anna", "Premoli", "Facciamo finta che mi ami", "667-432-178-4",d1);

    Book mybook3("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4", Date(6,8,1997));

    Book mybook4("Alessia", "Gazzola", "Le ossa della principessa", "135-999-087-7");

    BookShelf shelf;
    shelf.push_back(mybook1);
    shelf.push_back(mybook2);
    shelf.push_back(mybook3);
    shelf.push_back(mybook4);

    cout<<shelf<<"\n";


    cout<<"---------Elimino l'ultimo elemento--------"<<"\n";
    shelf.pop_back();
    cout<<shelf<<"\n";

    cout<<"---------gioco con i bookshelf--------"<<"\n";

    BookShelf shelf2;
    cout<<shelf2;
    shelf2=shelf;
    cout<<shelf2<<endl;
    //cout<<shelf2[100]; //va out of bounds e il prgramma non ritorna 0
    
    cout<<"---------Controllo se mybook4 e mybook2 sono uguali--------"<<"\n";

    if(mybook4==mybook2){
        cout<<"i due libri sono uguali";
    }
    else{
        cout<<"i due libri non sono uguali";
    }

    return 0;
}