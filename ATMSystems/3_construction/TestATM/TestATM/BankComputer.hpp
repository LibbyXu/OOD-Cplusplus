//
//  BankComputer.hpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#ifndef BankComputer_hpp
#define BankComputer_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Account.hpp"
#include "Card.hpp"
#include "Transaction.hpp"

class Transaction;

class BankComputer{
public:
    BankComputer(const std::string& newBankName);
    
    int getBankId(){return bankID;}
    std::string getBankName(){return bankName;}
    
    void addAccount(Account* newAccount);
    bool verifyTheStripNumber(Card* theVard);
    bool verifyThePin(Transaction* theTransaction);
    void requestWithdrawAmt(Transaction* theTransaction);

private:
    int bankID=9;
    std::string bankName;
    std::vector<Account*> accounts;
    static int numberOfBanks;
};

#endif /* BankComputer_hpp */
