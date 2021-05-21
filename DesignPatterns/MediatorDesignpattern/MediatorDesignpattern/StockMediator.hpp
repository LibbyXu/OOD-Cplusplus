//
//  StockMediator.hpp
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef StockMediator_hpp
#define StockMediator_hpp

#include <stdio.h>
#include <string>
#include "Colleague.hpp"

class StockMediator:public Mediator{
public:
    void addColleague(Colleague *colleague){
        listColl.push_back(colleague);
        colleagueNum++;
        colleague->setCollCode(colleagueNum);
    };
    void saleOffer(std::string stock, int shares, int code);
    void buyOffer(std::string stock, int shares, int code);
    void getStockOffering();

};

#endif /* StockMediator_hpp */
