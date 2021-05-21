//
//  ATMM.cpp
//  stateDesignPatterns
//
//  Created by Lihua Xu on 5/14/21.
//
#include <iostream>
#include "ATMM.hpp"

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
