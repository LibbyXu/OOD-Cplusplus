//
//  main.cpp
//  FacadDesignPatterns
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
using namespace std;

class BankWelcome{
public:
    BankWelcome(){
        cout << "Welome to the bank." << endl;
    };
};

class AccountNumberCheck{
public:
    int getAccountNum(){
        return accountNumber;
    };
    bool accountActive(int accNumToCheck){
        if(accNumToCheck==getAccountNum()){
            return true;
        }else{
            return false;
        }
    };
private:
    int accountNumber=3674674;
};

class SecurityCode{
public:
    int getSecurityCode(){
        return securityCode;
    };
    bool SecurityCodeCheck(int enteredCode){
        if(enteredCode==getSecurityCode()){
            return true;
        }
        return false;
    };
private:
    int securityCode=12345;
};

class fundsCheck{
public:
    double getCashInAccount(){
        return cashInAccount;
    };
    void decreaseCashInAccount(double cashWithdraw){
        cashInAccount-=cashWithdraw;
    };
    void increaseCashInAccount(double cashDeposite){
        cashInAccount+=cashDeposite;
    };
    bool haveEnoughMoney(double cashToWithdraw){
        if(getCashInAccount()>=cashToWithdraw){
            decreaseCashInAccount(cashToWithdraw);
            return true;
        }
        cout << "You don't have enough money." << endl;
        cout << "Current balance is " << getCashInAccount() << endl;
        return false;
    };
    void makeDeposite(double cashToDeposite){
        increaseCashInAccount(cashToDeposite);
        cout << "The Deposite completed: current balance is " << getCashInAccount() << endl;
    };
    
private:
    double cashInAccount = 1000.00;
};

class BankAccountFacade{
public:
    
    BankAccountFacade(int newAccountNum, int newSecCode){
        accountNumber=newAccountNum;
        securityCode=newSecCode;
        bankWel=new BankWelcome;
        acctChecker=new AccountNumberCheck;
        codeChecker=new SecurityCode;
        fundChecker=new fundsCheck;
    };
    
    int getAccountNum(){
        return accountNumber;
    };
    int getSecuCode(){
        return securityCode;
    };
    
    void withdrawCash(double cashToWithDraw){
        if(acctChecker->accountActive(getAccountNum()) && codeChecker->SecurityCodeCheck(getSecuCode())&& fundChecker->haveEnoughMoney(cashToWithDraw)){
            cout << "Transaction completed!" << "current balance is " << fundChecker->getCashInAccount() << endl;
        }else{
            cout << "Transaction Failed!" << endl;
        }
    };
    
    void depositeCash(double cashToDeposite){
        if(acctChecker->accountActive(getAccountNum()) && codeChecker->SecurityCodeCheck(getSecuCode())){
            cout << "Transaction completed!" << endl;
            fundChecker->makeDeposite(cashToDeposite);
        }else{
            cout << "Transaction Failed!" << endl;
        }
    };
    
private:
    int accountNumber;
    int securityCode;
    AccountNumberCheck *acctChecker;
    SecurityCode *codeChecker;
    fundsCheck *fundChecker;
    BankWelcome *bankWel;
};



int main(int argc, const char * argv[]) {

    BankAccountFacade *accessingBank = new BankAccountFacade(3674674, 12345);
    
    accessingBank->withdrawCash(50.0);
    accessingBank->withdrawCash(500.0);
    accessingBank->depositeCash(150.0);
    
    return 0;
}
