//
//  Liquor.h
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef Liquor_h
#define Liquor_h
#include "Items.h"
class Liquor:public items{
public:
    Liquor(double item):items(item){};
    double accept(Visitor *visitor){
        return visitor->visit(this);
    };
};

#endif /* Liquor_h */
