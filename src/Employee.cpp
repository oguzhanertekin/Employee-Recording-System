#include "Employee.h"
Employee::Employee(int Id,int Type,string Name,string Surname ,string Title ,double Salary,Date BirthD,Date AppointmentD,int ServiceLength):
id(Id),type(Type),name(Name),surname(Surname),title(Title),salary(Salary), birthD(BirthD), appointmentD(AppointmentD),serviceLength(ServiceLength){

}



const int Employee::getId() const {
    return id;
}
const int Employee::getType() const {
    return type;
}
const string &Employee::getName() const {
    return name;
}
const string &Employee::getSurname() const {
    return surname;
}
string Employee::getTitle(){
    return title;
}


void Employee::setTitle(string title) {
    Employee::title = title;
}
double Employee::getSalary() const {
    return salary;
}
void Employee::setSalary(double salary) {
    Employee::salary = salary;
}
const Date &Employee::getBirthD() const {
    return birthD;
}
const Date &Employee::getAppointmentD() const {
    return appointmentD;
}
const int Employee::getServiceLength() const {
    return serviceLength;
}

ostream& operator<<(ostream& os,const Employee& employee){
    os<<"Employee ID: "<<employee.id<<"\nType:"<<employee.type<<"\nName:"<<employee.name<<"\nSurname:"<<employee.surname<<"\nTitle:"
    <<employee.title<<"\nSalary:"<<employee.salary<<"\nBirthDate:"<<employee.birthD<<"\nAppointmentDate:"<<employee.appointmentD<<"\nServiceLength:"<<employee.serviceLength<<endl;

    return os;
}







