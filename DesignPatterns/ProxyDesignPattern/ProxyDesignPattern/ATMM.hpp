//
//  ATMM.hpp
//  stateDesignPatterns
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef ATMM_hpp
#define ATMM_hpp

#include <stdio.h>
#include "ATMS.hpp"
#include "ATMDATA.h"


class ATMMachine:public GetATMData{
public:
    ATMMachine(){
        hasCard=new HasCard(this);
        noCard=new NoCard(this);
        hasCorrectPin=new HasCorrectPin(this);
        ATMoutOfMoney=new ATMOutOfMoney(this);
        
        curState=noCard;
        
        if(cashInMacine<=0){
            curState=ATMoutOfMoney;
        }
    };
    
    void setATMstates(ATMState *newATMState);
    void setCashInMachine(int newCashInMachine);
    void insertCard();
    void ejectCard();
    void requestCash(int cashToWithdraw);
    void insertPin(int enteredPin);
    ATMState* getYesCardState();
    ATMState* getNoCardState();
    ATMState* getHasPin();
    ATMState* getNoCashState();
    void setCorrectPinEntered();
    int getCashInMachine();
    void getATMData();
private:
    ATMState *hasCard;
    ATMState *noCard;
    ATMState *hasCorrectPin;
    ATMState *ATMoutOfMoney;
    
    ATMState *curState;
    
    int cashInMacine = 2000;
    bool correctPinEntered = false;
};
#endif /* ATMM_hpp */

