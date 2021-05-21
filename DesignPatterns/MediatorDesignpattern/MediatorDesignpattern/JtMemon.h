//
//  JtMemon.h
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef JtMemon_h
#define JtMemon_h
#include "Colleague.hpp"
#include "Mediator.h"
class JtMemon:public Colleague{
public:
    JtMemon(Mediator *newMediator):Colleague(newMediator){
        mediator=newMediator;
        std::cout << "JtMemon signed for the exchange." << std::endl;
    }
};


#endif /* JtMemon_h */
