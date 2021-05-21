//
//  Mediator.h
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef Mediator_h
#define Mediator_h
#include "StockOffer.h"
#include "Colleague.hpp"
#include <vector>
#include <string>
using namespace std;
class Colleague;

class Mediator{
public:
    virtual void saleOffer(std::string stock, int shares, int code)=0;
    virtual void buyOffer(std::string stock, int shares, int code)=0;
    virtual void addColleague(Colleague *colleague)=0;
    virtual void getStockOffering()=0;
protected:
    vector<Colleague*>listColl;
    vector<StockOffer*>stockBuyOffers;
    vector<StockOffer*>stockSaleOffers;
    int colleagueNum=0;
};

#endif /* Mediator_h */
