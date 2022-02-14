#include "Date.h"

Date::Date(int Day,int Month,int Year) : day(Day),month(Month),year(Year) {
}

const int Date::getDay() const {
    return day;
}
const int Date::getMonth() const {
    return month;
}
const int Date::getYear() const {
    return year;
}


const int Date::operator<(const Date &date2) const {
    if(year==date2.year && month==date2.month && day==date2.day  ){
        return 1;
    }
    if(year<date2.year){
        return 1;
    }
    if (year==date2.year && month<date2.month){
        return 1;
    }
    if(year==date2.year  && day<date2.day){
        return 1;
    }
    return 0;
}

ostream& operator<<(ostream& os,const Date& dt){
    os<<dt.getDay()<<"-"<<dt.getMonth()<<"-"<<dt.getYear();

    return os;
}


