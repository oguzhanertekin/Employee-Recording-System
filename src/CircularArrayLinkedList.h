
#ifndef ASS2_CIRCULARARRAYLINKEDLIST_H
#define ASS2_CIRCULARARRAYLINKEDLIST_H
#define MAX 20
#include<iostream>
#include "TemporaryEmployee.h"
#include <string>
using namespace std;

struct CircularNode{
    TemporaryEmployee *data;
    int next;
};


class CircularArrayLinkedList{
public:
    CircularNode cnode[20];
    int current;
    int head;
    int last;
    CircularArrayLinkedList();
    ~CircularArrayLinkedList();
    void add(TemporaryEmployee *employee);
    bool ifExist(int id);
    void display();
    void remove(int id);
    void sort();
    void update(int id,string title,double salary);
    void show(int id);
    void PrintAfterDate(Date date);
    void PrintGivenYear(int year);
    void PrintBornBefore(Date date);
    void PrintGivenMonth(int month);


};

#endif //ASS2_CIRCULARARRAYLINKEDLIST_H
