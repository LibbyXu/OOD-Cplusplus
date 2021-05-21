//
//  Card.cpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#include "Card.hpp"
#include <string>

//constructor
Card::Card(const int& stripNumber):stripNumber(stripNumber){}
Card::Card(const int& pin,const int& stripNumber):stripNumber(stripNumber),pin(pin){}

//Methods
void Card::setPin(int newPin){
    pin=newPin;
}

void Card::setStripNumber(int newStripNumber){
    stripNumber=newStripNumber;
}
