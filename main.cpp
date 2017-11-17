//============================================================================
// Name        : airlineDB.cpp
// Author      : Beau Shirdavani
// Version     : 2
// Description : Airline DB - Assignment # 2
// Date           : Nov 2, 2017
//============================================================================

#include "LinkedList.hpp"
#include "Passenger.hpp"
#include "OrderedLinkedList.hpp"
#include <iostream>
//#include <typeinfo>
using namespace std;


// my original problem was on line 64 here, I cannot add a second passenger to the ordered linked list.

int main(){
    //*******************************************************
    //                                      make sample passengers
    Passenger* P_1;
    P_1 = new Passenger("steve", "smith", "5012 245th ave ne Redmond, WA 98052", "425-885-5535");
    Passenger* P_2;
    P_2 = new Passenger("jason", "dillon", "5012 245th ave ne Seattle, WA 98052", "206-261-1256");
    Passenger* P_3;
    P_3 = new Passenger("mads", "michaelson", "5555 555th ave ne Hollywood, CA 98052", "555-555-5555");
    Passenger* P_4;
    P_4 = new Passenger("peter", "pan", "never never land, CA 98052", "555-555-5555");
    Passenger* P_5;
    P_5 = new Passenger("howard", "hughes", "america somewhere", "555-555-5555");
    Passenger* P_6;
    P_6 = new Passenger("donnie", "darko", "in the movies", "555-555-5555");
    Passenger* P_7;
    P_7 = new Passenger("donald", "duck", "disney world", "555-555-5555");
    Passenger* P_8;
    P_8 = new Passenger("mickey", "mouse", "disney world", "555-555-5555");
    //*******************************************************
    //                                      make flight lists
    OrderedLinkedList<Passenger>* fl_100;
    fl_100 = new OrderedLinkedList<Passenger>();
    OrderedLinkedList<Passenger>* fl_200;
    fl_200 = new OrderedLinkedList<Passenger>();
    OrderedLinkedList<Passenger>* fl_300;
    fl_300 = new OrderedLinkedList<Passenger>();
    OrderedLinkedList<Passenger>* fl_400;
    fl_400 = new OrderedLinkedList<Passenger>();
    //*******************************************************
    //                                      put passengers on flights
    fl_100->addPassenger(*P_1);
    fl_100->addPassenger(*P_2);
    fl_100->addPassenger(*P_3);
    fl_100->addPassenger(*P_4);
    fl_200->addPassenger(*P_3);
    fl_200->addPassenger(*P_5);
    fl_300->addPassenger(*P_5);
    fl_300->addPassenger(*P_6);
    fl_300->addPassenger(*P_7);
    fl_400->addPassenger(*P_8);
    
    
    
    
    //*******************************************************
    //                                      setup MENU for program interface
    int _flightIN;
    string _fNameIN;
    string _lNameIN;
    string _addrIN;
    string _phoneIN;
    char _choiceIN = NULL;
    cout << "*** DELTA AIRLINES ***" << endl;
    while ( _choiceIN != 'Q' ){
        cout << "Please choose an operation:" << endl;
        cout << "A (Add) | S (Search | D (Delete) | L (List) | Q (Quit): ";
        cin >> _choiceIN;
        cin.ignore();
        //*******************************************************
        //                                      define options
        //-------------------------------------------------------
        //                                                  ADD
        if ( _choiceIN == 'A' ){
            cout << "Enter flight number: ";
            cin >> _flightIN;
            cin.ignore();
            cout << "Enter First Name: ";
            cin >> _fNameIN;
            cin.ignore();
            cout << "Enter Last Name: ";
            cin >> _lNameIN;
            cin.ignore();
            cout << "Enter address: ";
            getline(cin, _addrIN);
//            cin.ignore();
            cout << "Enter phone: ";
            getline(cin, _phoneIN);
//            cin.ignore();
            Passenger* _newPASS;
            _newPASS = new Passenger(_fNameIN, _lNameIN, _addrIN, _phoneIN);
            switch (_flightIN) {
                case 100:
                    fl_100->addPassenger(*_newPASS);
                    break;
                case 200:
                    fl_200->addPassenger(*_newPASS);
                    break;
                case 300:
                    fl_300->addPassenger(*_newPASS);
                    break;
                case 400:
                    fl_400->addPassenger(*_newPASS);
                    break;
                default:
                    break;
            }
        }
        //-------------------------------------------------------
        //                                                  Search
        else if ( _choiceIN == 'S'){
            cout << "Enter a Last name: ";
            cin >> _lNameIN;
            cin.ignore();
            Passenger* _newPASS;
            _newPASS = new Passenger("default", _lNameIN, "default", "default");
            if ( fl_100->search(*_newPASS) ){
                cout << "Flight Number: 100" << endl;
                cout << "First Name: " << fl_100->search(*_newPASS)->data.getFirstName() << endl;
                cout << "Last Name: " << fl_100->search(*_newPASS)->data.getLastName() << endl;
                cout << "Address: " << fl_100->search(*_newPASS)->data.getAddress() << endl;
                cout << "Phone: " << fl_100->search(*_newPASS)->data.getPhone() << endl;
//                cout << ( fl_100->search(*P_2) )->data;
            }
            if ( fl_200->search(*_newPASS) ){
                cout << "Flight Number: 200" << endl;
                cout << "First Name: " << fl_200->search(*_newPASS)->data.getFirstName() << endl;
                cout << "Last Name: " << fl_200->search(*_newPASS)->data.getLastName() << endl;
                cout << "Address: " << fl_200->search(*_newPASS)->data.getAddress() << endl;
                cout << "Phone: " << fl_200->search(*_newPASS)->data.getPhone() << endl;
            }
            if ( fl_300->search(*_newPASS) ){
                cout << "Flight Number: 300" << endl;
                cout << "First Name: " << fl_300->search(*_newPASS)->data.getFirstName() << endl;
                cout << "Last Name: " << fl_300->search(*_newPASS)->data.getLastName() << endl;
                cout << "Address: " << fl_300->search(*_newPASS)->data.getAddress() << endl;
                cout << "Phone: " << fl_300->search(*_newPASS)->data.getPhone() << endl;
            }
            if ( fl_400->search(*_newPASS) ){
                cout << "Flight Number: 400" << endl;
                cout << "First Name: " << fl_400->search(*_newPASS)->data.getFirstName() << endl;
                cout << "Last Name: " << fl_400->search(*_newPASS)->data.getLastName() << endl;
                cout << "Address: " << fl_400->search(*_newPASS)->data.getAddress() << endl;
                cout << "Phone: " << fl_400->search(*_newPASS)->data.getPhone() << endl;
            }
        }
        //-------------------------------------------------------
        //                                                  Delete
        else if ( _choiceIN == 'D'){
            cout << "Enter a Flight Number: ";
            cin >> _fNameIN;
            cin.ignore();
            cout << "Enter First Name: ";
            cin >> _fNameIN;
            cin.ignore();
            cout << "Enter Last Name: ";
            cin >> _lNameIN;
            cin.ignore();
            Passenger* _newPASS;
            _newPASS = new Passenger(_fNameIN, _lNameIN, "default", "default");
            switch (_flightIN) {
                case 100:
                    fl_100->deleteNode(*_newPASS);
                    break;
                case 200:
                    fl_200->deleteNode(*_newPASS);
                    break;
                case 300:
                    fl_300->deleteNode(*_newPASS);
                    break;
                case 400:
                    fl_400->deleteNode(*_newPASS);
                    break;
                default:
                    break;
            }
        }
        
        //-------------------------------------------------------
        //                                                  List
        else if ( _choiceIN == 'L' ){
            cout << "Enter a flight number: ";
            cin >> _flightIN;
            cin.ignore();
            switch (_flightIN) {
                case 100:
                    cout << *fl_100 << endl;
                    break;
                case 200:
                    cout << *fl_200 << endl;
                    break;
                case 300:
                    cout << *fl_300 << endl;
                    break;
                case 400:
                    cout << *fl_400 << endl;
                    break;
                default:
                    break;
            }
        }
        //-------------------------------------------------------
        //                                                  Quit

        
    }
    
    

    
//
//    LinkedList<Passenger>* listPASS;
//    listPASS = new LinkedList<Passenger>();
//    listPASS->inserFirst(*P_1);
//    listPASS->inserFirst(*P_2);
//    listPASS->inserFirst(*P_3);
//    cout << "<< for list*: " << endl << *listPASS << endl;
//    cout << "length of list: \t" << listPASS->length() << endl;
//
//    cout << "Test search from main NOW: \t" << endl;
//    cout << ( listPASS->search(*P_2) )->data << endl;
//    cout << listPASS->length() << endl;
//    listPASS->deleteNode(*P_2);
//    cout << "<< for list*: " << endl << *listPASS << endl;
//    cout << listPASS->length() << endl;
//    listPASS->deleteNode(*P_3);
//    cout << "<< for list*: " << endl << *listPASS << endl;
//    cout << listPASS->length() << endl;
//    listPASS->deleteNode(*P_1);
//    cout << "<< for list*: " << endl << *listPASS << endl;
//    cout << listPASS->length() << endl;
//    listPASS->addPassenger(*P_1);
//    cout << listPASS->length() << endl;
//
//
//    cout << "P_2 < P_3: " << (P_2 < P_3) << endl;
//
//
//    cout << "\n\nORDERED LINKED LIST TEST." << endl;
//    OrderedLinkedList<Passenger>* oList;
//    oList = new OrderedLinkedList<Passenger>();
//    oList->addPassenger(*P_1);
//    cout << oList->length() << endl;
//    cout << *oList << endl;
//    oList->addPassenger(*P_2);
//    cout << oList->length() << endl;
//    cout << *oList << endl;
//    cout << "P_3: " << *P_3 << endl;
//    oList->addPassenger(*P_3);
//    cout << oList->length() << endl;
//    cout << *oList << endl;
//
//    cout << "\n\nORDERED SEARCH TEST." << endl;
//    cout << ( oList->search(*P_2) )->data << endl;
//    cout << ( oList->search(*P_1) )->data << endl;
//    cout << ( oList->search(*P_3) )->data << endl;
//
//    cout << "\n\nORDERED DELETE" << endl;
//    cout << oList->length() << endl;
//    oList->deleteNode(*P_1);
//    cout << oList->length() << endl;
//    cout << *oList << endl;
//    oList->deleteNode(*P_2);
//    cout << oList->length() << endl;
//    cout << *oList << endl;
//    oList->deleteNode(*P_2);
//    cout << oList->length() << endl;
//    cout << *oList << endl;
//
    
    
    return 0;
}
