#include <string>
#include "Date.h"
using namespace std;


#ifndef ASS2_EMPLOYEE_H
#define ASS2_EMPLOYEE_H




class Employee {
public:
    Employee(int id,int type,string name,string surname,string title,double salary,Date birthD,Date appointmentD,int serviceLength);



    const int getId() const;
    const int getType() const;
    const string &getName() const;
    const string &getSurname() const;
    string getTitle();
    void setTitle(string title);
    double getSalary() const;
    void setSalary(double salary);
    const Date &getBirthD() const;
    const Date &getAppointmentD() const;
    const int getServiceLength() const;
    friend ostream& operator<<(ostream& os, const Employee& employee);

private:
    const int id;
    const int type;
    const string name;
    const string surname;
    string title;
    double salary;
    const Date birthD;
    const Date appointmentD;
    const int serviceLength;

};






#endif //ASS2_EMPLOYEE_H
