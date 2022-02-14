
#include "Employee.h"
#ifndef ASS2_TEMPORARYEMPLOYEE_H
#define ASS2_TEMPORARYEMPLOYEE_H


class TemporaryEmployee:public Employee {
public:
    TemporaryEmployee(int id,int type,string name,string surname,string title,double salary,Date birthD,Date appointmentD,int serviceLength);

};


#endif //ASS2_TEMPORARYEMPLOYEE_H
