//
//  Colleague.hpp
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef Colleague_hpp
#define Colleague_hpp
#include "Mediator.h"
#include <string>

class Mediator;

class Colleague{
public:
    Colleague(Mediator *newMediator){
        mediator=newMediator;
    };
    
    void saleOffer(std::string stock, int shares);
    void buyOffer(std::string stock, int shares);
    void setCollCode(int collCode);
    
protected:
    Mediator *mediator;
    int colleagCode;
};
#include <stdio.h>

#endif /* Colleague_hpp */
