
#include "Employee.h"
#include <string>
#ifndef ASS2_PERMANENTEMPLOYEE_H
#define ASS2_PERMANENTEMPLOYEE_H


class PermanentEmployee:public Employee {
public:
    PermanentEmployee(int id,int type,string name,string surname,string title,double salary,Date birthD,Date appointmentD,int serviceLength);

};


#endif //ASS2_PERMANENTEMPLOYEE_H
