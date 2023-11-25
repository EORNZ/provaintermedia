#ifndef DATA_DATE_H
#define DATA_DATE_H

#include <iostream>


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
    bool operator<(const Date &) const;
    bool operator>(const Date &) const;
    //ausiliari
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    bool isIgnoto() const;
    //toString
    std::string toString() const;

private:
    int giorno;
    int mese;
    int anno;
};

//ostream
std::ostream &operator<<(std::ostream &os, const Date &);

#endif //DATA_DATE_H
