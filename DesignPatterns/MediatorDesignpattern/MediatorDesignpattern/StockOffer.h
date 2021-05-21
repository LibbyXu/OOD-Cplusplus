//
//  StockOffer.h
//  MediatorDesignpattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef StockOffer_h
#define StockOffer_h
#include <string>
class StockOffer{
public:
    StockOffer(int share, std::string name, int coll){
        stockShares=share;
        stockSymbol=name;
        colleagueCode=coll;
    };
    
    int getStockShares(){return stockShares;};
    std::string getstockSymbol(){return stockSymbol;};
    int getcolleagueCode(){return colleagueCode;};
    
private:
    int stockShares=0;
    std::string stockSymbol;
    int colleagueCode=0;
};

#endif /* StockOffer_h */
