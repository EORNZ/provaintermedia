#include "../include/Date.h"

//costruttori
Date::Date(){
    this->giorno=0;
    this->mese=0;
    this->anno=0;
}

Date::Date(int gg, int mm, int aaaa) {
    if((gg > 0 && gg < 32) && (mm > 0 && mm < 13) && (aaaa >= 1 && aaaa <= 2024)){
        if((gg>29 && mm==2 && aaaa%4==0) || (gg > 28 && mm == 2 && aaaa%4!=0) || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && gg > 30)){
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
Date& Date::operator=(const Date& d){
    this->giorno = d.giorno;
    this->mese = d.mese;
    this->anno = d.anno;
    return *this;
}

bool Date::operator==(const Date &d) const {
    return (this->giorno == d.giorno && this->mese == d.mese && this->anno == d.anno);
}

bool Date::operator!=(const Date &d) const {
    return !operator==(d);
}

bool Date::operator<(const Date &d) const {
    if(giorno==0 || mese==0 || anno==0)
        return false;

    if (this->anno < d.anno)
        return true;
    else if (this->anno > d.anno)
        return false;

    if (this->mese < d.mese)
        return true;
    else if (this->mese > d.mese)
        return false;

    return giorno < d.giorno;
}

bool Date::operator>(const Date &d) const {
    if(giorno==0 || mese==0 || anno==0)
        return false;
    return !(*this < d);
}

//ausiliari
int Date::getGiorno() const{
    return giorno;
}
int Date::getMese() const{
    return mese;
}
int Date::getAnno() const{
    return anno;
}

//toString
std::string Date::toString() const{
    std::string s;
    if(giorno==0 || mese==0 || anno==0){
        s= "Data ignota";
    }
    else{
        s = std::to_string(giorno) + "/" + std::to_string(mese) + "/" + std::to_string(anno);
    }
    return s;
}

//ostream
std::ostream &operator<<(std::ostream &os, const Date &d)
{
    return os << d.toString();
}