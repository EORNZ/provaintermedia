Prova intermedia
Autori: Novkovic Elena, Renzi Edoardo, Zago Giada

Scelte progettuali
- classe Date
  Il costruttore di default inizializza i membri a 0 e assumiamo che una data con tali valori sia IGNOTA
-classe Book
  Il costruttore di default assegna agli attributi membro stringhe vuote e la data la rende di default cioè col significato di ignota. Questo costruttore non andrebbe utilizzato per la creazione di oggetti libro in quanto un libro con i membri non assegnati non dovrebbe esistere ma lo abbiamo dovuto creare per il vettore BookShelf.
  Così anche per i costruttori che non richiedono una data come parametro: la data viene costruita con il costruttore Date() di default e la assumiamo come ignota.
  

-classe BookShelf
