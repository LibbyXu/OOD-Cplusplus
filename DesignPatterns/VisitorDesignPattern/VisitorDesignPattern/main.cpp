//
//  main.cpp
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include <iostream>
#include <vector>
#include <string>
#include "Visitor.h"
#include "Items.h"
#include "Liquor.h"
#include "Necessity.h"
#include "Tabacco.h"
#include "TaxVisitor.h"
#include "TaxHolidayVisitor.h"
using namespace std;

//Difference between the interface and the abstruct class in C++

//c++中interface class通常不带成员变量，也没有构造函数，只有一个visual析构函数以及一组pure visual函数，用来叙述整个接口。虽然类似Java和.net的interface，但是C++的interface class并不需要复旦Java和.net的interface所需负担的责任。
//这里顺带说明接口继承和实现继承：
//
//所谓接口继承就是派生类只继承函数的接口，也就是声明。而实现继承就是派生类同时继承函数的接口和实现。
//
//声明一个纯虚函数（pure visual）的目的就是为了让派生类只继承函数接口，即接口继承。
//声明一个非纯虚函数（impure visual）的目的是为了让派生类继承函数接口和缺省实现。
//声明一个非虚函数（non visual）的目的是为了让派生类继承函数接口和一份强制实现。


int main(int argc, const char * argv[]) {
 
    Liquor* liqu=new Liquor(7.98);
    Tabacco* tabac=new Tabacco(8.96);
    Necessity* ness=new Necessity(23.56);
    
    Visitor* cur1=new TaxVisitor;
    Visitor* cur2=new TaxHolidayVisitor;

    cout << "Common day visitor: \n";
    cout << liqu->accept(cur1) << endl;
    cout << tabac->accept(cur1) << endl;
    cout << ness->accept(cur1) << endl;

    
    cout << "Holiday visitor: \n";
    cout << liqu->accept(cur2) << endl;
    cout << tabac->accept(cur2) << endl;
    cout << ness->accept(cur2) << endl;
    
    return 0;
}
