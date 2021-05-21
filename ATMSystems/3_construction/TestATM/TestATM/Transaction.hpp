//
//  Transaction.hpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#ifndef Transaction_hpp
#define Transaction_hpp

#include <stdio.h>
#include <string>
#include "BankNetwork.hpp"

class Transaction{
public:
    Transaction(const int& stripNumber);
    
    int getBankId(){return bankID;}
    std::string getCustomerName(){return customerName;}
    int getStripNumber(){return stripNumber;}
    int getPin(){return pin;}
    bool getDidCardVerify(){return didCardVerify;}
    int getAcctToWithdrawalFrom(){return acctToWithdrawalFrom;}
    double getWithdrawalAmt(){return withDrawalAmt;}
    double getAcctBalance(){return acctBalance;}
    int getAcctNumberUsed(){return acctNumberUsed;}
    
    void setCustormerName(std::string newCustomerName);
    void setPin(int newPin);
    void setStripNumber(int newStripNumber);
    void setDidCardVerify(bool cardVerified);
    void setAcctToWithdrawalFrom(int newAcctToWithdrawalFrom);
    void setWithdrawalAmt(double newWithdrawalAmt);
    void setActBalance(double newAcctBalance);
    std::string getCurrentDateTime(){return currentDateTime;}
private:
    int bankID;
    std::string currentDateTime;
    std::string customerName;
    double acctBalance;
    double withDrawalAmt;
    int acctNumberUsed;
    int pin;
    int stripNumber;
    int acctToWithdrawalFrom;
    bool didCardVerify=false;
    const std::string currentDateTimeCalcu();
};


#endif /* Transaction_hpp */
