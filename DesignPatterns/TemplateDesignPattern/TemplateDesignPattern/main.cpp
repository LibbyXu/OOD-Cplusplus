//
//  main.cpp
//  TemplateDesignPattern
//
//  Created by Lihua Xu on 5/12/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hoagie{
public:
    void makeSandwitch(){
        cutBun();
        if(customerWantsMeat())addMeat();
        if(customerWantsCheese())addCheese();
        if(customerWantsVegetables())addVegetables();
        if(customerWantsCondiments())addCondiments();
        wrapTheHoagia();
    };
    
    void cutBun(){
        cout << "The hoagia is Cut." << endl;
    };
    virtual void addMeat()=0;
    virtual bool customerWantsMeat(){
        return true;
    };
    
    virtual void addCheese()=0;
    virtual bool customerWantsCheese(){
        return true;
    };
    
    virtual void addVegetables()=0;
    virtual bool customerWantsVegetables(){
        return true;
    };
    
    virtual void addCondiments()=0;
    virtual bool customerWantsCondiments(){
        return true;
    };
    
    void wrapTheHoagia(){
        cout << "The Hoagia has been wrapped." << endl;
    };
};

class ItalianHoagie:public Hoagie{
public:
    void addMeat(){
        cout << "Adding Meat :" << endl;
        for(const auto & s:meatUsed){
            cout << s << " ";
        }
        cout << endl;
    };
    void addCheese(){
        cout << "Adding Cheese :" << endl;
        for(const auto & s:cheeseUsed){
            cout << s << " ";
        }
        cout << endl;
    };
    void addVegetables(){
        cout << "Adding Veges :" << endl;
        for(const auto & s:vegesUsed){
            cout << s << " ";
        }
        cout<< endl;
    };
    void addCondiments(){
        cout << "Adding Condiments :" << endl;
        for(const auto & s:condimentUsed){
            cout << s << " ";
        }
        cout << endl;
    };
private:
    vector<string>meatUsed={"Salami","Pepperoni","Capicola Ham"};
    vector<string>cheeseUsed={"Provolon"};
    vector<string>vegesUsed={"Onions","Tomatoes","Pepper"};
    vector<string>condimentUsed={"Oil","Vinegar"};
};

class VetableHoagie:public Hoagie{
public:
    bool customerWantsMeat()override{
        return false;
    };
    bool customerWantsCheese()override{
        return false;
    };
    
    void addMeat()override{};
    void addCheese()override{};
    
    void addVegetables() override{
        cout << "Adding Veges :" << endl;
        for(const auto & s:vegesUsed){
            cout << s << " ";
        }
        cout << endl;
    };
    void addCondiments() override{
        cout << "Adding Condiments :" << endl;
        for(const auto & s:condimentUsed){
            cout << s << " ";
        }
        cout << endl;
    };
private:
    vector<string>vegesUsed={"Onions","Tomatoes","Pepper"};
    vector<string>condimentUsed={"Oil","Vinegar"};
};

int main(int argc, const char * argv[]) {
 
    Hoagie *theSanwitch=new ItalianHoagie();
    theSanwitch->makeSandwitch();
    
    Hoagie *theSanwitch_new=new VetableHoagie();
    theSanwitch_new->makeSandwitch();
    return 0;
}
