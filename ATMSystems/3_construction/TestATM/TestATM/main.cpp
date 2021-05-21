//
//  main.cpp
//  TestATM
//
//  Created by Lihua Xu on 5/19/21.
//

#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"
#include "Card.hpp"
#include "Customer.hpp"
#include "BankComputer.hpp"
#include "BankNetwork.hpp"
#include "ATM.hpp"
#include "Transaction.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    //Create my account
    Account *theAccount= new Account(10, "Libby", "C", 10000.00, 6789);
    
    //Generate an ATM card for the new customer
    Card *customerCard=new Card(theAccount->getPin(),theAccount->getStripNumber());
    
    //Create the Customer object and give it an ATM card
    Customer *theCustomer=new Customer(customerCard);
    
    //Create the BankComputer that will hold the account
    BankComputer *xyzBankComputer=new BankComputer("XYZ Bank");
    
    //Add the account to the BankComputer system
    xyzBankComputer->addAccount(theAccount);
    
    //Create a network that will hold every bank computer and all tje accounts they hold
    BankNetwork *theBankNetwork=new BankNetwork();

    //Add the BankComputer into the BankNetwork
    theBankNetwork->addBankToNetwork(xyzBankComputer);
    
    //Create a ATM machine that will allow access to all BankComputer in the BnakNetwork
    ATM *mainStreetATM=new ATM(theBankNetwork);
    
    //Check with the ATM to find out if the card os readable
    mainStreetATM->isStripRedable(customerCard);
    
    //Create with the BankNetwork to see if the cards member bank is part of the network
    mainStreetATM->isATMCardBankInNetword(customerCard);
    
    //customerATMCard and the pin are verified by the ATM
    mainStreetATM->insertPin(customerCard, 6789);
    
    //Asks the customer weather to withdraw money from checking or savings
    mainStreetATM->pickAcctToAccess();
    
    //Asks the customer how much money they want to withdrawal
    mainStreetATM->amtToWithdraw();
    
    //Provides info on the Transaction
    mainStreetATM->getTransactionInfo();
    
    return 0;
}
