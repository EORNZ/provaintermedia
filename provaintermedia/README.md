
# Prova Intermedia

Il programma è progettato per gestire una libreria di libri utilizzando tre classi principali: Date, Book, e BookShelf. La classe Date è stata creata per rappresentare una data con le varibili membro giorno, mese e anno. La classe Book contiene informazioni su un libro, con variabili membro isbn, titolo, nome, cognome, data e stato(che rappresenta la disponibilità del libro). Infine, la classe BookShelf rappresenta la libreria sotto forma di vettore, contenente un array di Book (elem), la dimensione attuale (size) e la dimensione massima possibile (buffer_size).


## Struttura del codice

Il codice è organizzato nelle seguenti directory:

📦 provaintermedia  
┣📂 include  
┃ ┣ 📜 Book.h  
┃ ┣ 📜 BookShelf.h  
┃ ┣ 📜 Date.h  
┣📂 src  
┃ ┣ 📜 Date.cpp  
┃ ┣ 📜 BookShelf.cpp  
┃ ┣ 📜 Date.cpp  
┃ ┣ 📜 main.cpp  
┣📜 CMakeLists.txt  
┣📜 README.md  

dove

1. **`include`**: Contiene i file header.
    - `Book.h`: Contiene la definizione della classe `Book`.
    - `BookShelf.h`: Contiene la definizione della classe `BookShelf`. 
    - `Date.h`: Contiene la definizione della classe `Date`.
    
2. **`src`**: Contiene i file sorgente.
    - `Book.cpp`: Contiene l'implementazione della classe `Book`.
    - `BookShelf.h` e `BookShelf.cpp`: Contiene l'implementazione della classe `BookShelf`.
    - `Date.cpp`: Contiene l'implementazione della classe `Date` .
    - `main.cpp`: Un file sorgente di esempio che illustra come utilizzare le classi nel tuo progetto.

3. `CMakeLists.txt`: Gestisce i file nella compilazione del programma

## Scelte progettuali
- classe Date  
  Il costruttore di default inizializza i membri a 0 e assumiamo che una data con tali valori sia IGNOTA
- classe Book  
  Il costruttore di default assegna agli attributi membro stringhe vuote e la data la rende di default cioè col significato di ignota. 
  Questo costruttore non andrebbe utilizzato per la creazione di oggetti libro in quanto un libro con i membri non assegnati non dovrebbe esistere ma lo abbiamo dovuto creare per il vettore BookShelf.
  Così anche per i costruttori che non richiedono una data come parametro: la data viene costruita con il costruttore `Date()` di default e la assumiamo come ignota.

## Esempio d'utilizzo del codice

```cpp
Date dataPubblicazione(1, 1, 2023);
Book libro1("123456789", "Titolo Libro", "Nome Autore", "Cognome Autore", dataPubblicazione);
Book libro2("987654321", "Altro Titolo", "Altro Nome", "Altro Cognome", 2, 2, 2022);

BookShelf libreria;
libreria.addBook(libro1);
libreria.addBook(libro2);

```

## Autori (in ordine alfabetico)

- [Novkovic Elena](https://www.github.com/eenvk)
- [Renzi Edoardo](https://www.github.com/EORNZ)
- [Zago Giada](https://www.github.com/Jada03)
