//
//  Card.hpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

class Card{
public:
    Card(const int& strpNumber);
    Card(const int& pin,const int& stripNumber);
    
    int getStripNumber(){return stripNumber;}
    int getPin(){return pin;}
    
    void setPin(int newPin);
    void setStripNumber(int newStripNumber);    
private:
    int stripNumber;
    int pin;
};


#endif /* Card_hpp */
