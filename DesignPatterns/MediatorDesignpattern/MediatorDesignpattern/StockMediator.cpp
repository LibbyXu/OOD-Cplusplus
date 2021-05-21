//
//  StockMediator.cpp
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include "StockMediator.hpp"
#include <string>
#include <iostream>
using namespace std;

void StockMediator::saleOffer(string stock, int shares, int code){
    bool stockSold=false;
    for(auto iter=stockBuyOffers.begin();iter!=stockBuyOffers.end();++iter){
        if((*iter)->getstockSymbol()==stock && (*iter)->getStockShares()==shares){
            cout << shares << " shares of " << stock << " sold to colleague code " << (*iter)->getcolleagueCode() << endl;
            stockBuyOffers.erase(iter);
            stockSold=true;
        }
        if(stockSold)break;
    };
    if(!stockSold){
        cout << shares << " shares of " << stock <<" added to inventory. " << endl;
        
        StockOffer *newOffering=new StockOffer(shares,stock,code);
        stockSaleOffers.push_back(newOffering);
    }
};

void StockMediator::buyOffer(string stock, int shares, int code){
    bool stockBought=false;
    for(auto iter=stockSaleOffers.begin();iter!=stockSaleOffers.end();++iter){
        if((*iter)->getstockSymbol()==stock && (*iter)->getStockShares()==shares){
            cout << shares << " shares of " << stock << " bought buy colleague code " << (*iter)->getcolleagueCode() << endl;
            stockSaleOffers.erase(iter);
            stockBought=true;
        }
        if(stockBought)break;
    };
    if(!stockBought){
        cout << shares << " shares of " << stock <<" added to inventory. " << endl;
        
        StockOffer *newSelling=new StockOffer(shares, stock,code);
        stockBuyOffers.push_back(newSelling);
    }
};

void StockMediator::getStockOffering(){
    cout << "Stocks For Sale: " << endl;
    
    for(auto iter=stockSaleOffers.begin();iter!=stockSaleOffers.end();++iter){
        cout << (*iter)->getStockShares() << " shares of " << (*iter)->getstockSymbol() << endl;
    };
    
    cout << "Stocks buy offers: " << endl;
    
    for(auto iter=stockBuyOffers.begin();iter!=stockBuyOffers.end();++iter){
        cout << (*iter)->getStockShares() << " shares of " << (*iter)->getstockSymbol() << endl;
    };
};
