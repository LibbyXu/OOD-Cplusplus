//
//  TaxVisitor.h
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef TaxVisitor_h
#define TaxVisitor_h
#include "Visitor.h"
#include "Liquor.h"
#include "Tabacco.h"
#include "Necessity.h"
class TaxVisitor:public Visitor{
public:
    TaxVisitor(){};
    double visit(Liquor *liquor){
        std::cout << "liquor item: Price with Tax ";
        return liquor->getPrice()*(0.18+1);
    };
    double visit(Tabacco *tabacco){
        std::cout << "tabacco item: Price with Tax ";
        return tabacco->getPrice()*(0.23+1);
    };
    double visit(Necessity *necessity){
        std::cout << "necessity item: Price with Tax ";
        return necessity->getPrice()*(0+1);
    };
};


#endif /* TaxVisitor_h */
