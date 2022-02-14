//
// Created by oerte on 27.11.2021.
//

#include "DoubleDynamicLinkedList.h"
#include <string>
using namespace std;
Node::Node(const PermanentEmployee *employee):data(*employee){
    next= NULL;
    prev= NULL;
}

DoubleDynamicLinkedList::DoubleDynamicLinkedList() {
    head = NULL;

}

DoubleDynamicLinkedList::~DoubleDynamicLinkedList() {

}

Node *DoubleDynamicLinkedList::ifExist(int id) {
    Node * temp = NULL;
    Node * head = this->head;

    while (head != NULL) {
        if (id==head -> data.getId()) {
            temp = head;}
        head= head -> next;
    }
    return temp;
}


void DoubleDynamicLinkedList::addNode(Node* node) {
    if (ifExist(node->data.getId()) != NULL) {
        return;
    } else {
        Node* current;
        if (head == NULL) {
            head = node;
        }
        else if (!(head->data.getAppointmentD() < node->data.getAppointmentD())) {
            node->next = head;
            node->next->prev = node;
            head = node;
        }

        else {
            current = head;

            while (current->next != NULL &&
                   current->next->data.getAppointmentD() < node->data.getAppointmentD())
                current = current->next;

            node->next = current->next;

            if (current->next != NULL)
                node->next->prev = node;

            current->next = node;
            node->prev = current;
        }
    }
}




void DoubleDynamicLinkedList::removeNode(int id) {
    Node * ptr =  ifExist(id);
    if (ptr == NULL) {

    } else {

        if (head -> data.getId() == id) {
            head = head -> next;

        } else {
            Node * nextNode = ptr -> next;
            Node * prevNode = ptr -> prev;
            if (nextNode == NULL) {
                prevNode -> next = NULL;

            }

            else {
                prevNode -> next = nextNode;
                nextNode -> prev = prevNode;

            }
            delete(ptr);
        }
    }
}

void DoubleDynamicLinkedList::update(int id, string title, double salary) {
    Node * ptr = ifExist(id);
    if (ptr != NULL) {
        ptr -> data.setTitle(title);
        ptr->data.setSalary(salary);
    }

}

PermanentEmployee DoubleDynamicLinkedList::search(int id) {
    Node *ptr = ifExist(id);
    if (ptr != NULL) {
        return ptr->data;
    } else{
        return ptr->data;
    }
}

void DoubleDynamicLinkedList::show() {
    if (head == NULL) {

    } else {
        Node * temp = head;
        while (temp != NULL) {
            cout << temp->data<<endl;
            temp = temp -> next;
        }
    }
}




int DoubleDynamicLinkedList::searchID(int id) {
    Node *ptr = ifExist(id);
    if (ptr != NULL) {
        return 1;
    } else{
        return 0;
    }
}
void DoubleDynamicLinkedList::PrintReverse() {
    Node* curr;
    curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    while(curr->prev != NULL)
    {
        cout <<curr->data<< endl;
        curr = curr->prev;
    }

}

void DoubleDynamicLinkedList::PrintAfterDate(Date date) {
    Node* curr;
    curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    while(curr->prev != NULL)
    {
        if(date<curr->data.getAppointmentD()){
            cout <<curr->data<< endl;
            curr = curr->prev;
        } else{
            curr = curr->prev;
        }




    }

}

void DoubleDynamicLinkedList::PrintGivenYear(int year) {
    if (head == NULL) {

    } else {

        Node * temp = head;
        while (temp != NULL) {
            if(year==temp->data.getAppointmentD().getYear()){
                cout << temp->data<<endl;
                temp = temp -> next;
            }
            else{
                temp = temp -> next;
            }

        }

    }
}

void DoubleDynamicLinkedList::PrintBornBefore(Date date) {
    if (head == NULL) {

    } else {


        Node * temp = head;
        while (temp != NULL) {
            if(!(date<temp->data.getBirthD())){
                cout << temp->data<<endl;
                temp = temp -> next;
            }
            else{
                temp = temp -> next;
            }

        }
    }
}
void DoubleDynamicLinkedList::PrintGivenMonth(int month) {
    if (head == NULL) {

    } else {
        Node * temp = head;
        while (temp != NULL) {
            if(month==temp->data.getBirthD().getMonth()){
                cout << temp->data<<endl;
                temp = temp -> next;
            }
            else{
                temp = temp -> next;
            }

        }
    }
}
void DoubleDynamicLinkedList::PrintGivenTitle(string title) {
    Node* curr;
    curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    while(curr->prev != NULL)
    {
        if(title==curr->data.getTitle()){
            cout <<curr->data<< endl;
            break;
        } else{
            curr = curr->prev;
        }

    }
}









