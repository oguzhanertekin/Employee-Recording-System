#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "DoubleDynamicLinkedList.h"
#include "CircularArrayLinkedList.h"
using namespace std;

int strToint(string int_x){ // Converting string to int function
    stringstream value(int_x);
    int number;
    value >> number;
    return number;
}  // converts string to int

int* split(string str){
    int* commandArray=new int[3];
    string strToken;
    int index=0;

    stringstream X(str);
    while(getline(X,strToken,'-')){
        commandArray[index]= strToint(strToken);
        index++;

    }
    return commandArray;
}  // splits strings according to certain value
void enterInfo(int &type,string &name,string &surname,string &title,double &salary,string &birthD,string &appD){
    cout<<"Type the employee type:\n";
    cin>>type;
    cout<<"Type the name:\n";
    cin>>name;
    cout<<"Type the surname:\n";
    cin>>surname;
    cout<<"Type  title:\n";
    cin>>title;
    cout<<"Type salary coefficient:\n";
    cin>>salary;
    cout<<"Type birth date:\n";
    cin>>birthD;
    cout<<"Type appointment date:\n";
    cin>>appD;
}

int main() {

    DoubleDynamicLinkedList permList;
    CircularArrayLinkedList tempList;


    bool key = true;
    while (key){
        cout << "___ Employee Recording System ___" << endl;
        cout << "Please selecct for the following Menu Operation:" << endl;
        cout << "1) Appointment of a new employee" << endl;
        cout << "2) Appointment of a transferred employee" << endl;
        cout << "3) Updating the title and salary coefficient of an employee" << endl;
        cout << "4) Deletion of an employee" << endl;
        cout << "5) Listing the information of an employee" << endl;
        cout << "6) Listing employees ordered by employee number" << endl;
        cout << "7) Listing employees ordered by appointment date" << endl;
        cout << "8) Listing employees appointed after a certain date" << endl;
        cout << "9) Listing employees assigned in a given year" << endl;
        cout << "10) Listing employees born before a certain date" << endl;
        cout << "11) Listing employees born in particular month" << endl;
        cout << "12) Listing the information of the last assigned employee with a given title" << endl;

        int option;
        cin >> option;
        cout << "Option: " << option << endl;  //



        if (option == 1){
            int id;
            cout << "Please type the employee number:\n";
            cin>>id;
            if(permList.searchID(id)){
                cout<<"The employee with this number already exists\n\n";
            }

            else if(tempList.ifExist(id)){
                cout<<"The employee with this number already exists\n\n";
            }
            else{
                int type;
                string name,surname,title,birthD,appointmentD;
                double salary;

                enterInfo(type,name,surname,title,salary,birthD,appointmentD);
                int birthDay,birthMonth,birthYear;
                birthDay=split(birthD)[0];
                birthMonth=split(birthD)[1];
                birthYear=split(birthD)[2];
                Date BirthD(birthDay,birthMonth,birthYear);
                int appDay,appMonth,appYear;
                appDay=split(appointmentD)[0];
                appMonth=split(appointmentD)[1];
                appYear=split(appointmentD)[2];
                Date AppD(appDay,appMonth,appYear);
                if(type==1){
                    PermanentEmployee* permEmployee=new PermanentEmployee(id,type,name,surname,title,salary,BirthD,AppD,0);
                    Node* node=new Node(permEmployee);
                    permList.addNode(node);

                }
                else if(type==0){
                    TemporaryEmployee* tempEmployee=new TemporaryEmployee(id,type,name,surname,title,salary,BirthD,AppD,0);
                    tempList.add(tempEmployee);

                }

            }


        }
        if (option == 2){
            int id;
            cout << "Please type the employee number:\n";
            cin>>id;
            if(permList.searchID(id)){
                cout<<"The employee with this number already exists\n\n";
            }

            else if(tempList.ifExist(id)){
                cout<<"The employee with this number already exists\n\n";
            }
            else{
                int type,lengthservice;
                string name,surname,title,birthD,appointmentD;
                double salary;

                enterInfo(type,name,surname,title,salary,birthD,appointmentD);
                int birthDay,birthMonth,birthYear;
                birthDay=split(birthD)[0];
                birthMonth=split(birthD)[1];
                birthYear=split(birthD)[2];
                Date BirthD(birthDay,birthMonth,birthYear);
                int appDay,appMonth,appYear;
                appDay=split(appointmentD)[0];
                appMonth=split(appointmentD)[1];
                appYear=split(appointmentD)[2];
                Date AppD(appDay,appMonth,appYear);
                cout<<"Type length of service days:\n";
                cin>>lengthservice;
                if(type==1){
                    PermanentEmployee* permEmployee=new PermanentEmployee(id,type,name,surname,title,salary,BirthD,AppD,lengthservice);
                    Node* node=new Node(permEmployee);
                    permList.addNode(node);

                }
                else if(type==0){
                    TemporaryEmployee* tempEmployee=new TemporaryEmployee(id,type,name,surname,title,salary,BirthD,AppD,lengthservice);
                    tempList.add(tempEmployee);


                }

            }

        }
        if (option == 3){
            int id;
            cout << "Please type the employee number:\n";
            cin>>id;
            if(permList.searchID(id)){
                string title;
                double salary;
                cout << "Please type new title:\n";
                cin>>title;
                cout << "Please type new salary coefficient:\n";
                cin>>salary;
                permList.update(id,title,salary);

            }

            else if(tempList.ifExist(id)){
                string title;
                double salary;
                cout << "Please type new title:\n";
                cin>>title;
                cout << "Please type new salary coefficient:\n";
                cin>>salary;
                tempList.update(id,title,salary);

            }
            else{
                cout<<"There is no employee with this employee number!\n";
            }

        }
        if (option == 4){
            int id;
            cout << "Please type the employee number:\n";
            cin>>id;
            if(permList.searchID(id)){
                permList.removeNode(id);
            }

            else if(tempList.ifExist(id)){
                tempList.remove(id);
            }
            else{
                cout<<"There is no employee with this employee number!\n";
            }
        }
        if (option == 5){
            int id;
            cout << "Please type the employee number:\n";
            cin>>id;
            if(permList.searchID(id)){
                cout<<permList.search(id)<<endl;
            }

            else if(tempList.ifExist(id)){
                tempList.show(id);
            }
            else{
                cout<<"There is no employee with this employee number!\n";
            }
        }
        if (option == 6){
            permList.show();
            tempList.display();


        }
        if (option == 7){
            permList.PrintReverse();

        }
        if (option == 8){
            string dt;
            int day,month,year;
            cout<<"Type the appointment date: "<<endl;
            cin>>dt;
            day=split(dt)[0];
            month=split(dt)[1];
            year=split(dt)[2];
            Date date(day,month,year);
            permList.PrintAfterDate(date);
            tempList.PrintAfterDate(date);


        }
        if (option == 9){
            int year;
            cout<<"Type the appointment year: "<<endl;
            cin>>year;

            permList.PrintGivenYear(year);
            tempList.PrintGivenYear(year);
        }
        if (option == 10){
            string dt;
            int day,month,year;
            cout<<"Type the birth date: "<<endl;
            cin>>dt;
            day=split(dt)[0];
            month=split(dt)[1];
            year=split(dt)[2];
            Date date(day,month,year);
            permList.PrintBornBefore(date);
            tempList.PrintBornBefore(date);
        }
        if (option == 11){
            int month;
            cout<<"Type the birth month: "<<endl;
            cin>>month;
            permList.PrintGivenMonth(month);
            tempList.PrintGivenMonth(month);
        }
        if (option == 12){
            string title;
            cout<<"Type the title: "<<endl;
            cin>>title;
            permList.PrintGivenTitle(title);
        }

        if (option == 00){
            key = false;
        }
    }


    return 0;
}
