//
// Created by oerte on 27.11.2021.
//
#ifndef ASS2_DOUBLEDYNAMICLINKEDLIST_H
#define ASS2_DOUBLEDYNAMICLINKEDLIST_H
#include<iostream>
#include "PermanentEmployee.h"
#include <string>
using namespace std;

struct Node {
public:

    PermanentEmployee data;
    Node * next;
    Node * prev;

    Node(const PermanentEmployee *employee);

};

class DoubleDynamicLinkedList{
public:
    Node* head;
    DoubleDynamicLinkedList();
    ~DoubleDynamicLinkedList();
    Node* ifExist(int id);
    void addNode(Node* node);
    void removeNode(int id);
    void update(int id,string title,double salary);
    void show();
    PermanentEmployee search(int id);
    int searchID(int id);
    void PrintReverse();
    void PrintAfterDate(Date date);
    void PrintGivenYear(int year);
    void PrintBornBefore(Date date);
    void PrintGivenMonth(int month);
    void PrintGivenTitle(string title);
};






#endif //ASS2_DOUBLEDYNAMICLINKEDLIST_H
