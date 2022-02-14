#include "CircularArrayLinkedList.h"
#include <string>




CircularArrayLinkedList::CircularArrayLinkedList(){
    current=0;
    head=-1;
    last=-1;
    for (int i=0;i<MAX;i++) {
        cnode[i].next=-1;

    }

}
CircularArrayLinkedList::~CircularArrayLinkedList() {}

bool CircularArrayLinkedList::ifExist(int id){
    int key=0;
    while(cnode[key].next!=-1){
        if(cnode[key].data->getId()==id){
            return 1;
        }
        key++;
    }
    return 0;
}

void CircularArrayLinkedList::add(TemporaryEmployee *employee) {
    if(head<0){
        head++;
        last++;
        cnode[last].data=employee;
        cnode[last].next=(last+1)%MAX;
    }
    else{
        last++;
        cnode[last].data=employee;
        cnode[last].next=(last+1)%MAX;
        current++;

    }

}
void CircularArrayLinkedList::remove(int id) {
    int key=0;
    while(cnode[key].next!=-1){
        if(cnode[key].data->getId()==id){;
            free(&cnode[key].data);
            return;
        }
        key++;
    }
}

void CircularArrayLinkedList::display() {
    int key=0;
    while(cnode[key].next!=-1){
        cout<<*cnode[key].data<<endl;

        key++;
    }
}

void CircularArrayLinkedList::sort() {
    int i,j,min,temp;
    for(i=0;i<MAX-1;i++){
        min=i;
        for(j=i+1;j<MAX;j++){
            if(cnode[j].data->getId()<cnode[min].data->getId()){
                min=j;
                temp=cnode[i].next;
                cnode[i].next=cnode[min].next;
                cnode[min].next=temp;
            }
        }
    }
}

void CircularArrayLinkedList::update(int id, string title, double salary) {
    int key=0;
    while(cnode[key].next!=-1){
        if(cnode[key].data->getId()==id){
            cnode[key].data->setTitle(title);
            cnode[key].data->setSalary(salary);
        }
        key++;
    }
}

void CircularArrayLinkedList::show(int id) {
    int key=0;
    while(cnode[key].next!=-1){
        if(cnode[key].data->getId()==id){
            cout<<*cnode[key].data<<endl;
        }
        key++;
    }
}

void CircularArrayLinkedList::PrintAfterDate(Date date) {
    int key=0;
    while(cnode[key].next!=-1){
        if(date<cnode[key].data->getAppointmentD()){
            cout<<*cnode[key].data<<endl;}

        key++;
    }
}

void CircularArrayLinkedList::PrintGivenYear(int year) {
    int key=0;
    while(cnode[key].next!=-1){
        if(year==cnode[key].data->getAppointmentD().getYear()){
            cout<<*cnode[key].data<<endl;}

        key++;
    }
}

void CircularArrayLinkedList::PrintBornBefore(Date date) {
    int key=0;
    while(cnode[key].next!=-1){
        if(!(date<cnode[key].data->getBirthD())){
            cout<<*cnode[key].data<<endl;}

        key++;
    }
}
void CircularArrayLinkedList::PrintGivenMonth(int month) {
    int key=0;
    while(cnode[key].next!=-1){
        if(month==cnode[key].data->getBirthD().getMonth()){
            cout<<*cnode[key].data<<endl;}

        key++;
    }
}






