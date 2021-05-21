//
//  Transaction.cpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#include "Transaction.hpp"
#include <ctime>

//private function
const std::string Transaction::currentDateTimeCalcu() {
    time_t now = std::time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *std::localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d-%X", &tstruct);
    return buf;
}

//constructor
Transaction::Transaction(const int& stripNumber):stripNumber(stripNumber){
    BankNetwork BN;
    bankID=BN.getFirstTwoDigit(stripNumber);
    currentDateTime=currentDateTimeCalcu();
}

//Methods
void Transaction::setCustormerName(std::string newCustomerName){
    customerName=newCustomerName;
}

void Transaction::setPin(int newPin){
    pin=newPin;
}

void Transaction::setStripNumber(int newStripNumber){
    stripNumber=newStripNumber;
}

void Transaction::setDidCardVerify(bool cardVerified){
    didCardVerify=cardVerified?true:false;
}

void Transaction::setAcctToWithdrawalFrom(int newAcctToWithdrawalFrom){
    acctToWithdrawalFrom=newAcctToWithdrawalFrom;
    acctNumberUsed=(stripNumber*10)+acctToWithdrawalFrom;
}

void Transaction::setWithdrawalAmt(double newWithdrawalAmt){
    withDrawalAmt=newWithdrawalAmt;
}

void Transaction::setActBalance(double newAcctBalance){
    acctBalance=newAcctBalance;
}

