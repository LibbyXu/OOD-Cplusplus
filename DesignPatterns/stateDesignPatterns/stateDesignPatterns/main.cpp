//
//  main.cpp
//  stateDesignPatterns
//
//  Created by Lihua Xu on 5/13/21.
//

#include <iostream>
#include <string>
#include <vector>
#include "ATMM.hpp"
#include "ATMS.hpp"

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
    
    return 0;
}
