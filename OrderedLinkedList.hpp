//
//  OrderedLinkedList.hpp
//  assignment02_v2.1
//
//  Created by shy macbook on 11/11/17.
//  Copyright © 2017 Shy. All rights reserved.
//

#ifndef OrderedLinkedList_h
#define OrderedLinkedList_h

#include "LinkedList.hpp"
#include "Passenger.hpp"
#include <iostream>
using namespace std;

template <class T>
class OrderedLinkedList:public LinkedList<T>
{
//protected:
//    int count;
//    node<T> *head, *last;
public:
    void addPassenger(T&);      // was T&, now is T*
    void deleteNode(T&);
    node<T>* search(T&);
};


//***********************************************************
//                                                addPassenger()
//                                          alphabetical in order
//  incomplete, simply for testing purposes
//  will redefine with specs once program allows me to override functions
template <class T>
void OrderedLinkedList<T>::addPassenger(T& item){                       // was T&
//    cout << "\tAdding passenger with ordered alphabetical add." << endl;
//    cout << "\t\ttest from addPassenger Ordered: " << item << endl;
    node<T> *temp = new node<T>;
    temp->data = item;
    //  CASE 1: list is empty
    if ( this->isEmpty() ){
        cout << "\t\tadding to empty list" << endl;
        this->head = temp;
        this->last = this->head;
        this->head->next = NULL;
        this->count++;
    }
    else{
        //  CASE 2-4: search for spot in list
        node<T> *lookHere = this->head;
        node<T> *trail = this->head;
        cout << "trail before while: " << trail << endl;
        while ( (lookHere != NULL) && (item > lookHere->data) ){
//            cout << "\t\tsearching alphabetically for passenger spot...\n";
            trail = lookHere;
            lookHere = lookHere->next;
        }
        
        if (lookHere==NULL){ //if lookHere is null it means we reach to end, so we can vall inserLast from LinkedList class
            this->inserLast(item);
            this->count++;
        }
        else if (lookHere == this->head) //if lookHere is head means, new data should be the first node, we can call inserFirst from LinkedList class
            this->inserFirst(item);
        else{                      //middle case
            trail->next = temp;
            temp->next = lookHere;
            this->count++;
        }
        
    }
}

//***********************************************************
//                                                deleteNode()
//                                          optimized for ordered list
template <class T>
void OrderedLinkedList<T>::deleteNode(T& item){
    node<T> *lookHere = this->head;
    node<T> *trail = this->head;
    
    // if item is at head
    if( this->head->data == item ){
//        cout << "\tnode to delete found at head..." << endl;
        node<T>* p = this->head;
        this->head = this->head->next;
        delete p;
        this->count--;
        if( this->head==NULL ) this->last = NULL;
    }
    else {
        while ( (lookHere->data != item) && (lookHere != NULL) ){
            // passed range, break loop
            if ( lookHere->data > item ){
                cout << "Could not find the passenger: " << item << " on this list." << endl;
                break;
            }
            // haven't passed range yet, keep looking
            else if ( lookHere->data < item ){
                trail = lookHere;
                lookHere = lookHere->next;
            }
        }
            // did not find it
        if ( lookHere->data > item ){
            cout << "try different name, or different flight." << endl;
        }
            // found it
        else if ( lookHere->data == item ){
            trail->next = lookHere->next;
            this->count--;
            if ( this->last == lookHere ){
                this->last = trail;
            }
        }
    }
}



//***********************************************************
//                                                search()
template <class T>
node<T>* OrderedLinkedList<T>::search(T& item){
    node<T> *here = this->head;
    while( ( here->data != item ) && (here->next != NULL) && (here->data < item) ){
        here = here->next;  // type: was here = head->next;
    }
    if ( here->next == NULL ){
        if ( here->data == item){
//            cout << "\t\tFound passenger" << endl;
            return here;
        }
        else
            cout << "\t\tCould not find passenger" << endl;
        return 0;                       // xcode forces me to have return 0
    }
    else if ( (here->next != NULL) && (here->data == item) ){
//        cout << "\t\tFound passenger" << endl;
        return here;
    }
    else{
        cout << "\t\tCould not find passenger" << endl;
        return 0;                      // xcode forces me to have return 0
    }
}


#endif /* OrderedLinkedList_h */


















