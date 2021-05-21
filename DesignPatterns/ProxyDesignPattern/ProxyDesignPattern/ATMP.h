//
//  ATMP.h
//  ProxyDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef ATMP_h
#define ATMP_h
#include "ATMDATA.h"
#include "ATMM.hpp"

class ATMProxy:public GetATMData{
public:
    void getATMData(){
        ATMMachine* realATM=new ATMMachine();
        realATM->getATMData();
    };
    
    int getCashInMachine(){
        ATMMachine* realATM=new ATMMachine();
        return realATM->getCashInMachine();
    };
};


#endif /* ATMP_h */
