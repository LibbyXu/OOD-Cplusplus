//
//  main.cpp
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include <iostream>
#include <string>
#include <vector>
#include "StockOffer.h"
#include "Mediator.h"
#include "Colleague.hpp"
#include "StockMediator.hpp"
#include "GormanSlacks.h"
#include "JtMemon.h"
using namespace std;

int main(int argc, const char * argv[]) {
 
    StockMediator* nyse=new StockMediator();
    
    GormanSlacks *broker1= new GormanSlacks(nyse);
    JtMemon *broker2= new JtMemon(nyse);
    
    broker1->saleOffer("MSFT",100);
    broker2->saleOffer("BAIDU", 50);
    
    broker2->saleOffer("TSLA", 190);
    broker1->saleOffer("FACEBOOK",100);

    broker2->buyOffer("FACEBOOK", 100);
    broker1->buyOffer("TSLA",190);
    broker1->buyOffer("Amazon",78);
    
    nyse->getStockOffering();
    
    
    return 0;
}
