//
//  Account.cpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#include "Account.hpp"
#include <string>
#include <cctype>

//constructor
Account::Account(const int &bankId,const std::string &customerName,const std::string &acctType,double acctBalance,int pin):bankID(bankId),customerName(customerName),acctType(acctType),acctBalance(acctBalance){
    stripNumber=generateStripNumber(bankId);
    acctNumber=generateAcctNumber(stripNumber, acctType);
}

//define the static member
int Account::acctNumberIncrementor=100000;

//Methods
double Account::setAcctBalance(double newAcctBalance){
    acctBalance=newAcctBalance;
    return acctBalance;
}


int Account::generateStripNumber(const int &bankID){
    acctNumberIncrementor++;
    int newStripNum=(bankID*1000000)+acctNumberIncrementor;
    return newStripNum;
}


int Account::generateAcctNumber(const int& stripNumber, const std::string& acctType){
    int acctNum=stripNumber*10;
    if(tolower(acctType[0])=='c'){
        acctNum+=2;
    }else{
        acctNum+=1;
    }
    return acctNum;
}
