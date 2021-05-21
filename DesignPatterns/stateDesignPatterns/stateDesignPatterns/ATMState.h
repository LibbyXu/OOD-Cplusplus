//
//  ATMState.h
//  stateDesignPatterns
//
//  Created by Lihua Xu on 5/13/21.
//

#ifndef ATMState_h
#define ATMState_h
#include "atmMac.h"

class ATMState{
public:
    virtual void insertCard()=0;
    virtual void ejectCard()=0;
    virtual void insertPin(int pinEntered)=0;
    virtual void requestCash(int cashToWithdraw)=0;
};


class HasCard:public ATMState{
public:
    
    HasCard(ATMMachine* NewatmMachine){
        atmMachine=NewatmMachine;
    };
    
    void insertCard();
    void ejectCard();
    void insertPin(int pinEntered);
    void requestCash(int cashToWithdraw);
private:
    ATMMachine* atmMachine;
};

void HasCard::insertCard(){
    std::cout << "You cannot enter more than one card." << std::endl;
};
void HasCard::ejectCard(){
    std::cout << "card ejected" << std::endl;
    atmMachine->setATMstates(atmMachine->getNoCardState());
};
void HasCard::insertPin(int pinEntered){
    if(pinEntered==12345){
        std::cout << "Corrent!" << std::endl;
        atmMachine->setCorrectPinEntered();
        atmMachine->setATMstates(atmMachine->getHasPin());
    }else{
        std::cout << "Wrong!" << std::endl;
        ejectCard();
    }
};
void HasCard::requestCash(int cashToWithdraw){
    std::cout << "Enter Pin First!" << std::endl;
};






class NoCard:public ATMState{
public:
    
    NoCard(ATMMachine* NewatmMachine){
        atmMachine=NewatmMachine;
    };
    
    void insertCard();
    void ejectCard();
    void insertPin(int pinEntered);
    void requestCash(int cashToWithdraw);

private:
    ATMMachine* atmMachine;
    
};

void NoCard::insertCard(){
    std::cout << "Please enter a Pin." << std::endl;
    atmMachine->setATMstates(atmMachine->getYesCardState());
};
void NoCard::ejectCard(){
    std::cout << "Enter a card first" << std::endl;
};
void NoCard::insertPin(int pinEntered){
    std::cout << "Enter a card first" << std::endl;
};
void NoCard::requestCash(int cashToWithdraw){
    std::cout << "Enter a card first" << std::endl;
};





class HasCorrectPin:public ATMState{
public:
    
    HasCorrectPin(ATMMachine* NewatmMachine){
        atmMachine=NewatmMachine;
    };
    
    void insertCard();
    void ejectCard();
    void insertPin(int pinEntered);
    void requestCash(int cashToWithdraw);

private:
    ATMMachine* atmMachine;
};

void HasCorrectPin::insertCard(){
    std::cout << "You cannot enter more than one card." << std::endl;
};
void HasCorrectPin::ejectCard(){
    std::cout << "card ejected" << std::endl;
    atmMachine->setATMstates(atmMachine->getNoCardState());
};
void HasCorrectPin::insertPin(int pinEntered){
    std::cout << "Already entered the Pin." << std::endl;
};
void HasCorrectPin::requestCash(int cashToWithdraw){
    if(cashToWithdraw<=atmMachine->getCashInMachine()){
        std::cout << cashToWithdraw << " will be provided by the machine." << std::endl;
        atmMachine->setCashInMachine(atmMachine->getCashInMachine()-cashToWithdraw);
        ejectCard();
    }else{
        std::cout << "Dont have that cash." << std::endl;
        ejectCard();
    }
    
    if(atmMachine->getCashInMachine()<=10){
        atmMachine->setATMstates(atmMachine->getNoCashState());
    }
};





class ATMOutOfMoney:public ATMState{
public:
    
    ATMOutOfMoney(ATMMachine* NewatmMachine){
        atmMachine=NewatmMachine;
    };
    
    void insertCard();
    void ejectCard();
    void insertPin(int pinEntered);
    void requestCash(int cashToWithdraw);

private:
    ATMMachine* atmMachine;
};

void ATMOutOfMoney::insertCard(){
    std::cout << "We don't have maney in the machine." << std::endl;
};
void ATMOutOfMoney::ejectCard(){
    std::cout << "We don't have maney in the machine. You didnt enter a card." << std::endl;
};
void ATMOutOfMoney::insertPin(int pinEntered){
    std::cout << "We don't have maney in the machine." << std::endl;
};
void ATMOutOfMoney::requestCash(int cashToWithdraw){
    std::cout << "We don't have maney in the machine." << std::endl;
};




#endif /* ATMState_h */
