//
//  Visitor.h
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef Visitor_h
#define Visitor_h
class Liquor;
class Tabacco;
class Necessity;

class Visitor{
public:
    virtual double visit(Liquor *liquor)=0;
    virtual double visit(Tabacco *tabacco)=0;
    virtual double visit(Necessity *necessity)=0;
};

#endif /* Visitor_h */
