//
//  Account.hpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>

class Account{
public:
    Account(const int &banckId,const std::string &customerName,const std::string &actType, double acctBalance,int pin);
    
    //return type use the const is useless if it is 传值模式
    //const int& 比较有用但是要注意(十分小心) 这个引用
    int getBankID()const {return bankID;}
    int getPin()const {return pin;}
    int getAcctNumber()const {return acctNumber;}
    std::string getCustomerName()const {return customerName;}
    std::string getAcctType()const {return acctType;}
    double getAcctBalance()const {return acctBalance;}
    int getStripNumber()const {return stripNumber;}
    
    double setAcctBalance(double newAcctBalance);
    int generateStripNumber(const int &bankId);
    int generateAcctNumber(const int& stripNumber, const std::string& acctType);
private:
    int bankID;
    std::string customerName;
    std::string acctType;
    double acctBalance;
    int pin;
    int acctNumber;
    int stripNumber;
    static int acctNumberIncrementor;
};



#endif /* Account_hpp */
