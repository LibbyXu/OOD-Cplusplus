//
//  BankComputer.cpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#include "BankComputer.hpp"
#include "BankComputer.hpp"
#include "Card.hpp"
#include "Transaction.hpp"
#include <string>
#include <iostream>

//define the static member
int BankComputer::numberOfBanks=0;

//constructor
BankComputer::BankComputer(const std::string& newBankName):bankName(newBankName){
    numberOfBanks++;
    bankID+=numberOfBanks;
}

//methods
void BankComputer::addAccount(Account* newAccount){
    accounts.push_back(newAccount);
}

bool BankComputer::verifyTheStripNumber(Card* theCard){
    int theCardStripNum=theCard->getStripNumber();
    
    for(auto iter=accounts.cbegin();iter!=accounts.cend();iter++){
        if((*iter)->getStripNumber()==theCardStripNum){
            return true;
        }
    }
    return false;
}

bool BankComputer::verifyThePin(Transaction* theTransaction){
    int theTransPin=theTransaction->getPin();
    if(theTransaction->getDidCardVerify()){
        for(auto iter=accounts.cbegin();iter!=accounts.cend();iter++){
            if((*iter)->getPin()==theTransPin){
                theTransaction->setCustormerName((*iter)->getCustomerName());
                theTransaction->setActBalance((*iter)->getAcctBalance());
                return true;
            }
        }
    }
    return false;
}

void BankComputer::requestWithdrawAmt(Transaction* theTransaction){
    
    int theAcctUsed=theTransaction->getAcctNumberUsed();
    for(auto iter=accounts.cbegin();iter!=accounts.cend();iter++){
        if((*iter)->getAcctNumber()==theAcctUsed){
            if((*iter)->getAcctBalance()>=theTransaction->getWithdrawalAmt()){
                double newAcctBalance=(*iter)->getAcctBalance()-theTransaction->getWithdrawalAmt();
                (*iter)->setAcctBalance(newAcctBalance);
                theTransaction->setActBalance(newAcctBalance);
            }else{
                std::cout << "You cannot withdrawal that much money." << std::endl;
            }
        }
    }
}
