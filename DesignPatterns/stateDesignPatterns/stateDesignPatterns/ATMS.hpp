//
//  ATMS.hpp
//  stateDesignPatterns
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef ATMS_hpp
#define ATMS_hpp

#include <stdio.h>


class ATMMachine;

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


#endif /* ATMS_hpp */
