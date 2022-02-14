
#include <iostream>
using namespace std;

#ifndef ASS2_DATE_H
#define ASS2_DATE_H

class Date {
public:
    Date(int day,int month,int year);
    const int getDay() const;
    const int getMonth() const;
    const int getYear() const;
    const int operator<(const Date& date2) const;
    friend ostream& operator<<(ostream& os, const Date& dt);

private:
    const int day;
    const int month;
    const int year;

};

#endif //ASS2_DATE_H
