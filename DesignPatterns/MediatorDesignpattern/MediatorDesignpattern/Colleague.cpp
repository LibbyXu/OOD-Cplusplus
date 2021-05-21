//
//  Colleague.cpp
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include "Colleague.hpp"

#include <string>
#include <iostream>
using namespace std;

void Colleague::saleOffer(string stock, int shares){
    mediator->saleOffer(stock,shares, this->colleagCode);
};
void Colleague::buyOffer(string stock, int shares){
    mediator->buyOffer(stock,shares, this->colleagCode);
};
void Colleague::setCollCode(int collCode){colleagCode=collCode;};

