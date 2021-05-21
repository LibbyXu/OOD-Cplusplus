//
//  Tabacco.h
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef Tabacco_h
#define Tabacco_h
#include "Items.h"
class Tabacco:public items{
public:
    Tabacco(double item):items(item){};
    double accept(Visitor *visitor){
        return visitor->visit(this);
    };
};

#endif /* Tabacco_h */
