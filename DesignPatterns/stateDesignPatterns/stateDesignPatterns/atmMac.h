//
//  atmMac.h
//  stateDesignPatterns
//
//  Created by Lihua Xu on 5/13/21.
//

#ifndef atmMac_h
#define atmMac_h

#include "ATMState.h"

class ATMMachine{
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
private:
    ATMState *hasCard;
    ATMState *noCard;
    ATMState *hasCorrectPin;
    ATMState *ATMoutOfMoney;
    
    ATMState *curState;
    
    int cashInMacine = 2000;
    bool correctPinEntered = false;
};

//ATMMachine
void ATMMachine::setATMstates(ATMState *newATMState){
    curState=newATMState;
};
void ATMMachine::setCashInMachine(int newCashInMachine){
    cashInMacine=newCashInMachine;
};
void ATMMachine::insertCard(){
    curState->insertCard();
};
void ATMMachine::ejectCard(){
    curState->ejectCard();
};
void ATMMachine::requestCash(int cashToWithdraw){
    curState->requestCash(cashToWithdraw);
};
void ATMMachine::insertPin(int enteredPin){
    curState->insertPin(enteredPin);
};
ATMState* ATMMachine::getYesCardState(){
    return hasCard;
};
ATMState* ATMMachine::getNoCardState(){
    return noCard;
};
ATMState* ATMMachine::getHasPin(){
    return hasCorrectPin;
};
ATMState* ATMMachine::getNoCashState(){
    return ATMoutOfMoney;
};
int ATMMachine::getCashInMachine(){
    return cashInMacine;
};
void ATMMachine::setCorrectPinEntered(){
    if(correctPinEntered)correctPinEntered=true;
    else correctPinEntered=false;
};

#endif /* atmMac_h */
