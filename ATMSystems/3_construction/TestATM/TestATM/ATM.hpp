//
//  ATM.hpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#ifndef ATM_hpp
#define ATM_hpp

#include <stdio.h>
#include <string>
#include "Card.hpp"
#include "Transaction.hpp"

class BankNetwork;

class ATM{
public:
    ATM(BankNetwork *newBankNetwork);
    
    bool isStripRedable(Card *theCard);
    bool isATMCardBankInNetword(Card *theCard);
    bool insertPin(Card *theCard, int Pin);
    void pickAcctToAccess();
    void amtToWithdraw();
    void getTransactionInfo();
    
private:
    BankNetwork* networkBanksOnATM=nullptr;
    Transaction* theTransaction=nullptr;
};



#endif /* ATM_hpp */
