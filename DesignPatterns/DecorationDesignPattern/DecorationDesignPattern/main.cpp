//
//  main.cpp
//  DecorationDesignPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
using namespace std;

class Pizza{
public:
    virtual string getDescription()=0;
    virtual double getCost()=0;
};

class plainPizza:public Pizza{
public:
    plainPizza(){
        cout << "Adding Thin Dough" << endl;
    };
    string getDescription() override{
        return "Thin Dough";
    };
    double getCost() override{
        return 4.00;
    };
};

class ToppingDecorator:public Pizza{
public:
    ToppingDecorator(Pizza *newpizza){
        tempPizza=newpizza;
    };
    
    string getDescription()override{
        return tempPizza->getDescription();
    };
    double getCost()override{
        return tempPizza->getCost();
    };
protected:
    Pizza *tempPizza;
};

class Mozzarella:public ToppingDecorator{
public:
    Mozzarella(Pizza *newpizza):ToppingDecorator(nullptr){
        tempPizza=newpizza;
        
        cout << "Adding Moz" << endl;
    };
    
    string getDescription()override{
        return tempPizza->getDescription()+", Mozzarella";
    };
    
    double getCost()override{
        return tempPizza->getCost() + .50;
    };
};

class TomatoSauce:public ToppingDecorator{
public:
    TomatoSauce(Pizza *newpizza):ToppingDecorator(nullptr){
        tempPizza=newpizza;
        
        cout << "Adding TomatoSauce" << endl;
    };
    
    string getDescription()override{
        return tempPizza->getDescription()+", Tomato Sauce";
    };
    
    double getCost()override{
        return tempPizza->getCost() + .75;
    };
};

int main(int argc, const char * argv[]) {
    
    Pizza* cur=new TomatoSauce(new Mozzarella(new plainPizza));
    cout << cur->getCost() << endl;
    cout << cur->getDescription() << endl;
    return 0;
}
