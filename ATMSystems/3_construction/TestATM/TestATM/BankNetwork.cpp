//
//  BankNetwork.cpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#include "BankNetwork.hpp"
#include <string>
#include <iostream>
#include "BankComputer.hpp"
#include "Card.hpp"
#include "Transaction.hpp"

//private function
int BankNetwork::getFirstTwoDigit(int stripNumber){
    std::string SN=std::to_string(stripNumber);
    int ID=static_cast<int>(stol(SN.substr(0,2)));
    return ID;
}

//Methods
void BankNetwork::addBankToNetwork(BankComputer *theBank){
    bankInDatabase.push_back(theBank);
}

bool BankNetwork::isATMCardsInNetwork(Card *theCard){
    int CardBankID=getFirstTwoDigit(theCard->getStripNumber());
    
    for(auto iter=bankInDatabase.cbegin();iter!=bankInDatabase.cend();++iter){
        if((*iter)->getBankId()==CardBankID){
            return true;
        }
    }
    return false;
}

bool BankNetwork::verifyThePin(Transaction *theTransaction){
    
    if(theTransaction->getDidCardVerify()){
        for(auto iter=bankInDatabase.cbegin();iter!=bankInDatabase.cend();++iter){
            if((*iter)->getBankId()==theTransaction->getBankId()){
                (*iter)->verifyThePin(theTransaction);
                return true;
            }
        }
    }
    return false;
}

void BankNetwork::requestWithdrawAmt(Transaction *theTransaction){
    
    if(theTransaction->getDidCardVerify()){
        for(auto iter=bankInDatabase.cbegin();iter!=bankInDatabase.cend();++iter){
            if((*iter)->getBankId()==theTransaction->getBankId()){
                (*iter)->requestWithdrawAmt(theTransaction);
            }
        }
    }else{
        std::cout << "An error Occurred During the Withdrawal!" << std::endl;
    }
    
}

