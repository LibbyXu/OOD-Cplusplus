//
//  ATMS.cpp
//  stateDesignPatterns
//
//  Created by Lihua Xu on 5/14/21.
//
#include <iostream>
#include "ATMM.hpp"
#include "ATMS.hpp"

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

