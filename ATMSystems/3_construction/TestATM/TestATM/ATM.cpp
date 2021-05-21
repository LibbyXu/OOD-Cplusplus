//
//  ATM.cpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#include "ATM.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include <cctype>

//constructor
ATM::ATM(BankNetwork *newBankNetwork):networkBanksOnATM(newBankNetwork){}

//Methods;
bool ATM::isStripRedable(Card *theCard){
    int numberDigitOnCard=log10(theCard->getStripNumber())+1;
    
    theTransaction=new Transaction(theCard->getStripNumber());
    if(numberDigitOnCard==10)return true;
    else return false;    
}

bool ATM::isATMCardBankInNetword(Card *theCard){
    if(networkBanksOnATM->isATMCardsInNetwork(theCard)){
        theTransaction->setStripNumber(theCard->getStripNumber());
        theTransaction->setDidCardVerify(true);
        return true;
    }else return false;
}

bool ATM::insertPin(Card *theCard, int Pin){
    int numDigitPin=log10(Pin)+1;
    
    if(numDigitPin!=4){
        std::cout << "Please enter 4 digit Pin!" << std::endl;
        return false;
    }else{
        theTransaction->setPin(Pin);
        networkBanksOnATM->verifyThePin(theTransaction);
        return true;
    }
    return false;
}

void ATM::pickAcctToAccess(){
    std::cout << "What do you want to Withdrawal From: " << std::endl;
    std::cout << "(1 - Savings, 2 - Checking)" << std::endl;
    
    char input;
    
    if(std::cin>> input && (input=='1' || input=='2')){
        theTransaction->setAcctToWithdrawalFrom(input-'0');
    }else{
        std::cout << "Please enter number 1 - Savings or 2 - Checkings." << std::endl;
    }
    std::cout << std::endl;
}

void ATM::amtToWithdraw(){
    std::cout << "How much do you want to withdrawal?" << std::endl;
    std::cout << " (Increments of 10) " << std::endl;
    
    double numberEntered;
    if(std::cin >> numberEntered){
        theTransaction->setWithdrawalAmt(numberEntered);
        networkBanksOnATM->requestWithdrawAmt(theTransaction);
    }else{
        std::cout << "You entered an Invalid Amount." << std::endl;
    }
    std::cout << std::endl;
}

void ATM::getTransactionInfo(){
    std::cout << "Thank you " << theTransaction->getCustomerName() << +" for using the XYZ Bank ATM\n";
    std::cout << "Date / Time of Transaction: " << theTransaction->getCurrentDateTime() << std::endl;
    std::cout << "Transaction: ";
    
    if(theTransaction->getAcctToWithdrawalFrom()==1){
        std::cout << "Saving Account:\n";
        std::cout << "Your current balance is " << theTransaction->getAcctBalance() << std::endl;
    }else{
        std::cout << "Checking Account\n";
        std::cout << "Your current balance is " << theTransaction->getAcctBalance() << std::endl;
    }
    std::cout << std::endl;
}
