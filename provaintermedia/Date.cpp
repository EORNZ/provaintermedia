#include "Date.h"

//costruttori
Date::Date(){
    this->giorno = 1;
    this->mese = 1;
    this->anno = 1900;
}

Date::Date(int gg, int mm, int aaaa) {

    if((gg > 0 && gg < 32) && (mm > 0 && mm < 13) && (aaaa >= 1900 && aaaa <= 2024)){
        if((gg > 28 && mm == 2 ) || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && gg > 30)){
            throw InvalidDate();
        }
        else{
            this->giorno = gg;
            this->mese = mm;
            this->anno = aaaa;
        }
    }
    else{
        throw InvalidDate();
    }
}


//overloading operatori
Date Date::operator=(const Date& d){
    this->giorno = d.giorno;
    this->mese = d.mese;
    this->anno = d.anno;
    return Date(giorno,mese,anno);
}

bool Date::operator==(const Date &d) const {
    return (this->giorno == d.giorno && this->mese == d.mese && this->anno == d.anno);
}

bool Date::operator!=(const Date &d) const {
    return !operator==(d);
}

bool Date::operator<(const Date &d) const {
    if (this->anno < d.anno)
        return true;
    else if (this->anno > d.anno)
        return false;

    if (mese < d.mese)
        return true;
    else if (mese > d.mese)
        return false;

    return giorno < d.giorno;
}

bool Date::operator>(const Date &d) const {
    return !(*this < d);
}

//ausiliari
int Date::getGiorno() {
    return giorno;
}
int Date::getMese() {
    return mese;
}
int Date::getAnno() {
    return anno;
}

//toString
std::string Date::toString() const{
    std::string s = std::to_string(giorno) + "/" + std::to_string(mese) + "/" + std::to_string(anno);
    return s;
}

//ostream
std::ostream &operator<<(std::ostream &os, const Date &d)
{
    return os << d.toString();
}