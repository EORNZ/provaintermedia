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

    cout<<"----------------Stampo i libri contenuti in shelf ----------------\n"<<shelf<<endl;

    cout<<"Modifico il libro 1\n";
    shelf[0] = Book("Felicia", "Kingsley", "Matrimonio di convenienza", "222-222-222-1",Date(10,9,2017));

    cout<<"----------------Stampo i libri contenuti in shelf ----------------\n"<<shelf<<endl;

    cout<<"Prendo in prestito il libro 2\n";
    shelf[1].prendi();

    cout<<"----------------Stampo i libri contenuti in shelf ----------------\n"<<shelf<<endl;

    cout<<"\n*****************************************\n"<<endl;


    BookShelf shelf2 = BookShelf(2);
    shelf2.push_back(mybook1);
    shelf2.push_back(mybook2);
    shelf2.push_back(mybook3);
    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n";

    cout<<"Modifico il libro 3\n";
    shelf2[2] = mybook4;

    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n";

    cout<<"Elimino l'ultimo elemento"<<endl;
    shelf2.pop_back();

    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n";

    cout<<"Modifico il libro 1\n";
    shelf2[0] = shelf[0];

    cout<<"----------------Stampo i libri contenuti in shelf2 ----------------\n"<<shelf2<<"\n";
    cout<<"----------------Stampo i libri contenuti in shelf ----------------\n"<<shelf<<"\n";

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
    shelf3[2].prendi(); //mybook5 da disponibile diventa in prestito
    cout<<"\n----------------Creazione terza libreria: Shelf3, con differente inserimento----------------\n";
    cout<<shelf3;


    return 0;
}


//test main

/*Date d1 = Date(10,12,2023);

    Book mybook1("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1",10,9,2023);
    mybook1.prendi();

    Book mybook2("Anna", "Premoli", "Facciamo finta che mi ami", "667-432-178-4",d1);

    Book mybook3("David", "Foster Wallace", "Una cosa divertente che non faro mai più", "887-521-837-4", Date(6,8,1997));

    Book mybook4("Alessia", "Gazzola", "Le ossa della principessa", "135-999-087-7");

    BookShelf shelf;
    shelf.push_back(mybook1);
    shelf.push_back(mybook2);
    shelf.push_back(mybook3);
    shelf.push_back(mybook4);

    cout<<shelf<<"\n";

    cout<<"---------Elimino l'ultimo elemento--------"<<endl;
    shelf.pop_back();
    cout<<shelf<<"\n";

    cout<<"---------Controllo se mybook4 e mybook2 sono uguali--------"<<endl;

    int a = 1; //devono rimanere all'interno della size della shelf
    int b = 2;

    if(shelf[a]==shelf[b]){
        cout<<"i due libri sono uguali";
    }
    else{
        cout<<"i due libri non sono uguali";
    }

    cout<<"\n\n---------gioco con i bookshelf--------"<<endl;

    BookShelf shelf2;
    cout<<shelf2;
    shelf2=shelf;
    cout<<shelf2<<endl;
    //cout<<shelf2[100]; //va out of bounds e il prgramma non ritorna 0
    Book mybook12;
    BookShelf shelf55 = { mybook12 };
    cout<<shelf55;

    /* ATTENZIONE METODI COMMENTATI IN BOOKSHELF
    cout<< "\n\ntest con nuovo metodo per prendere un libro dentro una libreria \n";
    BookShelf shelfedo(10);
    Book book("David", "Foster Wallace", "Una cosa divertente che non faro mai più", "887-521-837-4", Date(6,8,1997));
    Book book2("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1",10,9,2023);
    shelfedo.push_back(book);
    shelfedo.push_back(book2);
    shelfedo.push_back(book);

    book.prendi();

    cout<<"book.prendi() stampo shelf \n"<<shelfedo<<"\n";

    shelfedo.prendi_libro(book);
    cout<<"shelf.prendi_libro(book) stampo shelf \n"<<shelfedo<<"\n";
    shelfedo.prendi_libro(book);
    cout<<"shelf.prendi_libro(book) stampo shelf \n"<<shelfedo<<"\n";
    shelfedo.prendi_libro(book);
    cout<<"shelf.prendi_libro(book) stampo shelf \n"<<shelfedo<<"\n";
    shelfedo.prendi_libro(book);
    cout<<"shelf.prendi_libro(book) stampo shelf \n"<<shelfedo<<"\n";
    shelfedo.restituisci_libro(book);
    cout<<"shelf.restituisci_libro(book) stampo shelf \n"<<shelfedo<<"\n";
 *
 *
 * -------------------------------------------------------------------------------------------
 * Book mybook1("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1",10,9,2023);
    mybook1.prendi();

    Date d1 = Date(10,12,2023);

    Book mybook2("Anna", "Premoli", "Facciamo finta che mi ami", "667-432-178-4",d1);

    Book mybook3("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4", Date(6,8,1997));

    Book mybook4("Alessia", "Gazzola", "Le ossa della principessa", "135-999-087-7");

    //creo un bookshelf
    BookShelf shelf = BookShelf(1);
    shelf.push_back(Book("Felicia", "Kingsley", "Una ragazza d'altri tempi", "341-127-009-1",Date(10,9,2023)));
    shelf.push_back(Book("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4", 6,8,1997));

    cout<<"Stampo i libri contenuti in shelf \n"<<shelf<<endl;

    cout<<"Modifico il libro 1\n";
    shelf[0] = Book("Felicia", "Kingsley", "Matrimonio di convenienza", "222-222-222-1",Date(10,9,2017));

    cout<<"Stampo i libri contenuti in shelf \n"<<shelf<<endl;

    cout<<"Prendo in prestito il libro 2\n";
    shelf[1].prendi();

    cout<<"Stampo i libri contenuti in shelf \n"<<shelf<<endl;

    cout<<"-----------"<<endl;


    BookShelf shelf2;
    shelf2.push_back(mybook1);
    shelf2.push_back(mybook2);
    shelf2.push_back(mybook3);
    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n";

    cout<<"Modifico il libro 3\n";
    shelf2[2] = mybook4;

    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n";

    cout<<"Elimino l'ultimo elemento"<<endl;
    shelf2.pop_back();

    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n";

    cout<<"Modifico il libro 1\n";
    shelf2[0] = shelf[0];

    cout<<"Stampo i libri contenuti in shelf2 \n"<<shelf2<<"\n";

    mybook3.prendi();
    mybook2.prendi();
    cout<<mybook3<<endl;
    cout<<shelf2<<endl;

    //essendo che mybook2 e mybook3 sono oggetti a se stanti e quando vengono inseriti in bookshelf in realtà vengono solo copiati
    //quando modifico li modifico non modifico l'oggetto uguale a loro in bookshelf


    //cout<<shelf2[100]; //va out of bounds e il prgramma non ritorna 0


    cout<<shelf[0]<<endl;
    cout<<shelf2[0]<<endl;
    if(shelf[0]==shelf2[0]){
        cout<<"Le due librerie hanno 2 libri uguali\n";
    } */