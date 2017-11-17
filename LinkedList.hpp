/*
 * LinkedList.h
 *
 */


#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Passenger.hpp"
using namespace std;

//***********************************************************
template <class T>
struct node{
    T data;
    node* next;
};

//***********************************************************
template <class T>
class LinkedList{
private:
    LinkedList(const LinkedList&)=delete; //copy constructor
    
protected:
    int count;
    node<T> *head, *last;
public:
    LinkedList();
    bool isEmpty();
    int length();
    T front();
    T back();
    void inserFirst(T&);
    virtual void addPassenger(T&);                          // was T&
    void inserLast(T&);
    virtual void deleteNode(T&);                //================================== NEW
    void destroylist();
    LinkedList<T>& operator=(LinkedList<T>&);
    template <class U>
    friend ostream& operator<<(ostream& os, LinkedList<U>& list);
    void printPassList();
    virtual node<T>* search(T&);                //================================== NEW
    ~LinkedList();
};


//***********************************************************
//                                                SEARCH() ================================ NEW

// PROBLEM 1:   if I do not use "return 0", then xcode errors: "reached end of non-void function"
//              But now, I cannot have the "could not find" message print when the passenger is
//              not found...
// PROBLEM 2:   I don't know if this is still "abstract", since I need to use members specific
//              to Passenger class, in order to search Passenger names?

template <class T>
node<T>* LinkedList<T>::search(T& item){
    node<T> *here = head;
    while( ( here->data != item ) && (here->next != NULL) ){
        here = here->next;  // type: was here = head->next;
    }
    if ( here->next == NULL ){
        cout << "\t\tCould not find passenger" << endl;
        return 0;                       // xcode forces me to have return 0
    }
    else if ( here->next != NULL ){
//        cout << "\t\tFound passenger" << endl;
        return here;
    }
    else{
        cout << "\t\tCould not find passenger" << endl;
        return 0;                      // xcode forces me to have return 0
    }
}


//***********************************************************
//                                                addPassenger()
//                                          simple insertFirst for now, will override later
template <class T>
void LinkedList<T>::addPassenger(T& item){
//    cout << "\tAdding passenger with simple add." << endl;
    node<T> *temp = new node<T>;
    temp->data = item;
    temp->next = head;
    head = temp;
    count++;
//    cout << "\t\ttest from addPassenger: " << item << endl;
    if(last==NULL) last = temp;
}

//***********************************************************
//                                                Constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = last = NULL;
    count = 0;
}
//***********************************************************
//                                                isEmpty
template <class T>
bool LinkedList<T>::isEmpty(){
    return head==NULL;
}
//***********************************************************
//                                                length
template <class T>
int LinkedList<T>::length(){
    return count;
}
//***********************************************************
//                                                front
template <class T>
T LinkedList<T>::front(){
    return head->data;
}
//***********************************************************
//                                                back
template <class T>
T LinkedList<T>::back(){
    return last->data;
}

//***********************************************************
//                                                insertFirst
template <class T>
void LinkedList<T>::inserFirst(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    temp->next = head;
    head = temp;
    count++;
//    cout << "\t\ttest from insertFirst: " << item << endl;
    if(last==NULL) last = temp;
}
    
//***********************************************************
//                                                insertLast
template <class T>
void LinkedList<T>::inserLast(T& item){
    node<T> *newnode = new node<T>;
    newnode->data = item;
    newnode->next = NULL;
    if(head==NULL){
        head = last = newnode;
    }else{
        last->next = newnode;
        last = newnode;
    }
    count++;
}
//***********************************************************
//                                                deleteNode
template <class T>
void LinkedList<T>::deleteNode(T& item){
    if(head == NULL)
        cout <<"\tempty list, nothing to delete..." << endl;
    else{
        if(head->data == item){
//            cout << "\tnode to delete found at head..." << endl;
            node<T>* p = head;
            head = head->next;
            delete p;
            count--;
            if(head==NULL) last = NULL;
        }else{
            node<T>* p = head;
            node<T>* q = p->next;
            while( (q != NULL) && (q->data != item) ){
//                cout << "\tsearching for node to delete...";
                p = q;
                q = q->next;
            }
            if( q!=NULL ){
//                cout << "\n\tFound node to delte..." << endl;
                p->next = q->next;
                count--;
                if(last == q) last = p;
                delete q;
            }
        }
    }
}
//***********************************************************
//                                                destroyList
template <class T>
void LinkedList<T>::destroylist(){
    node<T> *p;
    while(head != NULL){
        p = head;
        head = head->next;
        delete p;
    }
    last = NULL;
    count = 0;
}
//***********************************************************
//                                                =
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
    if(this!= &list){
        copylist(list);
    }
    return *this;
}
//***********************************************************
//                                                <<  ///////////////////////
template <class U>
ostream& operator<<(ostream& os, LinkedList<U>& list){
    node<U> *p = list.head;
    while(p!= NULL){
        os<<p->data<<" "<<endl;
        p = p->next;
    }
    return os;
}

//***********************************************************
//                                    printPassList()  ///////////////////////
//void printPassList(){
//    node *p = list.head;
//    while(p!= NULL){
//        os<<p->data<<" "<<endl;
//        p = p->next;
//    }
//}

//***********************************************************
//                                                destructor
template <class T>
LinkedList<T>::~LinkedList(){
    destroylist();
}


#endif /* LINKEDLIST_HPP */

