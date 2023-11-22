#ifndef DATA_DATE_H
#define DATA_DATE_H

#include <iostream>

/*enum class Month{
    jan = 1, feb, mar, apr, mag, giu, lug, ago, set, nov, dic
};*/

class InvalidDate{};

class Date{

public:
    //costruttori
    Date();
    Date(int,int,int);
    //overloading operatori
    Date& operator=(const Date&);
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator>(const Date &) const;
    bool operator<(const Date &) const;
    //ausiliari
    int getGiorno();
    int getMese();
    int getAnno();
    bool isIgnoto();
    //toString
    std::string toString() const;

private:
    int giorno;
    int mese;
    int anno;
    bool ignoto;
};

//ostream
std::ostream &operator<<(std::ostream &os, const Date &);

#endif //DATA_DATE_H