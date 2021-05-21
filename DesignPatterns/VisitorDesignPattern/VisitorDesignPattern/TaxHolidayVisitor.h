//
//  TaxHolidayVisitor.h
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef TaxHolidayVisitor_h
#define TaxHolidayVisitor_h
#include "Visitor.h"
#include "Liquor.h"
#include "Tabacco.h"
#include "Necessity.h"
class TaxHolidayVisitor:public Visitor{
public:
    TaxHolidayVisitor(){};
    double visit(Liquor *liquor){
        std::cout << "liquor item: Price with Tax ";
        return liquor->getPrice()*(0.23+1);
    };
    double visit(Tabacco *tabacco){
        std::cout << "tabacco item: Price with Tax ";
        return tabacco->getPrice()*(0.3+1);
    };
    double visit(Necessity *necessity){
        std::cout << "necessity item: Price with Tax ";
        return necessity->getPrice()*(0+1);
    };
};

#endif /* TaxHolidayVisitor_h */
