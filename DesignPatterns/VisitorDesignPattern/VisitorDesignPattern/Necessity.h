//
//  Necessity.h
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef Necessity_h
#define Necessity_h
#include "Items.h"
class Necessity:public items{
public:
    Necessity(double item):items(item){};
    double accept(Visitor *visitor){
        return visitor->visit(this);
    };
};
#endif /* Necessity_h */
