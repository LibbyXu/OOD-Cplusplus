//
//  Customer.hpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <string>

class Card;

class Customer{
public:
    Customer(Card *newATMCard);
    
    Card* getATMCard(){return customerATMCard;}
private:
    Card *customerATMCard;
};

#endif /* Customer_hpp */
