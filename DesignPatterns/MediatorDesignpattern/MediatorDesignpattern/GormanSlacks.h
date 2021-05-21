//
//  GormanSlacks.h
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef GormanSlacks_h
#define GormanSlacks_h
#include "Mediator.h"
#include "Colleague.hpp"

class GormanSlacks:public Colleague{
public:
    GormanSlacks(Mediator *newMediator):Colleague(newMediator){
        mediator=newMediator;
        std::cout << "GormanSlacks signed for the exchange." << std::endl;
    }
};

#endif /* GormanSlacks_h */
