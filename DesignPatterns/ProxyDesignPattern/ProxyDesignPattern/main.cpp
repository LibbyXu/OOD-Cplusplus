//
//  main.cpp
//  ProxyDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include <iostream>
#include <vector>
#include "ATMM.hpp"
#include "ATMS.hpp"
#include "ATMDATA.h"
#include "ATMP.h"
using namespace std;

int main(int argc, const char * argv[]) {
 
    ATMMachine * atmMachine=new ATMMachine();
    
    atmMachine->insertCard();
    atmMachine->ejectCard();
    atmMachine->insertCard();
    atmMachine->insertPin(12345);
    atmMachine->requestCash(2000);
    atmMachine->insertCard();
    atmMachine->insertPin(1234);
    
    GetATMData * realatm=new ATMMachine();
    GetATMData * realp=new ATMProxy();
    
    realp->getATMData();
    cout << realp->getCashInMachine() << endl;

    
    
    return 0;
}
