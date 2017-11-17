/*
 * Passenger.hpp
 *
 *  Created on: Nov 3, 2017
 *      Author: shy
 */

#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


// OVERRIDE ALL COMPARISON OPERATORS
// compare last names

//**************************************************************
//                                          Make Passenger Class
class Passenger{
    
private:
    //    Passenger(const Passenger&) = delete;     //copy constructor
    string mFirstName;
    string mLastName;
    string mAddress;
    string mPhone;
public:
    string getFirstName();
    string getLastName();
    string getAddress();
    string getPhone();
    void setFirstName(string);
    void setLastName(string);
    void setAddress(string);
    void setPhone(string);
    Passenger();                            // defult constructor
    Passenger(string, string, string, string);
    // fails to print passenger objects //////////////////////////////
    friend ostream& operator<<(ostream& os, Passenger& person);
    // workaround to pring passenger dat
//    friend bool opeartor<(Passenger& p1, Passenger& p2);
    // overload comparison operators
    bool operator==(Passenger&);
    bool operator<(Passenger&);
    bool operator>(Passenger&);
    bool operator!=(Passenger&);
    void print();
    };
    
    //**************************************************************
    //                                          define << operator
    
//    bool operator<(Passenger& p1, Passenger& p2){
//        if
//            }
    
    
    //**************************************************************
    //                                          define print()
    
    
    
    
#endif /* PASSENGER_HPP */
    

