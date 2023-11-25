#include <iostream>
#include "../include/Book.h"
#include "../include/BookShelf.h"

using namespace std;

int main() {

    Book mybook1("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1");
    mybook1.prendi();
    Date d1 = Date(10,12,2023);
    Book mybook2("Anna", "Premoli", "Facciamo finta che mi ami", "667-432-178-4",d1);
    Book mybook3("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4", Date(6,8,1997));
    Book mybook4("Alessia", "Gazzola", "Le ossa della principessa", "135-999-087-7");

    //creo un bookshelf
    BookShelf shelf = BookShelf(1);
    shelf.push_back(Book("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1",Date(10,9,2023)));
    shelf.push_back(Book("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4", 6,8,1997));

    cout<<"Stampo i libri contenuti in shelf\n"<<shelf<<endl<<endl;

    cout<<"Modifico il libro 1 cambiandone la data\n";
    shelf[0] = Book("Felicia", "Kingsley", "Matrimonio di convenienza", "222-222-222-1",Date(10,9,2017));
    cout<<"Stampo i libri contenuti in shelf\n"<<shelf<<endl<<endl;

    cout<<"Prendo in prestito il libro 2\n";
    shelf[1].prendi();
    cout<<"Stampo i libri contenuti in shelf\n"<<shelf<<endl;

    cout<<"\n*****************************************\n"<<endl;

    BookShelf shelf2 = BookShelf(2);
    shelf2.push_back(mybook1);
    shelf2.push_back(mybook2);
    shelf2.push_back(mybook3);
    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n\n";

    cout<<"Modifico il libro 3\n";
    shelf2[2] = mybook4;
    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n\n";

    cout<<"Elimino l'ultimo elemento"<<endl;
    shelf2.pop_back();
    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n\n";

    cout<<"Modifico il libro 1\n";
    shelf2[0] = shelf[0];
    cout<<"Stampo i libri contenuti in shelf2\n"<<shelf2<<"\n";
    cout<<"Stampo i libri contenuti in shelf\n"<<shelf<<"\n";

    cout<<"\n----------------Confronto due libri nella shelf----------------\n";
    cout<<"libro selezionato: '"<<shelf[0].getTitolo()<<"' "<<endl;
    cout<<"libro selezionato: '"<<shelf[1].getTitolo()<<"' "<<endl;

    if(shelf[0]==shelf[1]){
        cout<<"La libreria presenta 2 libri uguali\n";
    }else{
        cout<<"La libreria non presenta 2 libri uguali\n";
    }


    Book mybook5("Collen", "Hoover", "Ugly Love", "888-345-899-9");
    BookShelf shelf3{mybook1, mybook2, mybook5};
    cout<<"\n----------------Creazione terza libreria: Shelf3, con differente inserimento----------------\n"<<shelf3<<endl;
    cout<<"\nPrendo in prestito il libro 3\n";
    shelf3[2].prendi(); //mybook5 da disponibile diventa in prestito
    cout<<shelf3;

    return 0;

}