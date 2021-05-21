//
//  BankNetwork.hpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#ifndef BankNetwork_hpp
#define BankNetwork_hpp

#include <stdio.h>
#include <string>
#include <vector>

class BankComputer;
class Card;
class Transaction;

class BankNetwork{
public:
    BankNetwork()=default;
    
    void addBankToNetwork(BankComputer *theBank);
    bool isATMCardsInNetwork(Card *theCard);
    bool verifyThePin(Transaction *theTransaction);
    void requestWithdrawAmt(Transaction *theTransaction);
    static int getFirstTwoDigit(int stripNumber);
private:
    std::vector<BankComputer*> bankInDatabase;
};

#endif /* BankNetwork_hpp */
