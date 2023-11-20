//
// Created by edore on 20/11/2023.
//

#ifndef DATA_DATE_H
#define DATA_DATE_H

#include <iostream>

class InvalidDate{};
class Date{

public:
    Date();
    Date(int,int,int);
    Date operator=(const Date&);
    bool operator==(const Date&)const;
    bool operator!=(const Date&)const;
    bool operator>(const Date &) const;
    bool operator<(const Date &) const;
    int getGiorno();
    int getMese();
    int getAnno();
    std::string toString() const;

private:
    int giorno;
    int mese;
    int anno;
};

std::ostream &operator<<(std::ostream &os, const Date &);


#endif //DATA_DATE_H
