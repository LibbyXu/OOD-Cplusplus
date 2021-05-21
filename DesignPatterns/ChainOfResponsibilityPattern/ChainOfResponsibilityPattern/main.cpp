//
//  main.cpp
//  ChainOfResponsibilityPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Numbers{
public:
    Numbers(int newNumber1, int newNumber2, string calcWanted):number_1(newNumber1),number_2(newNumber2),calculationWanted(calcWanted){};
    int getNumber1(){return number_1;};
    int getNumber2(){return number_2;};
    string getCalcumethod(){return calculationWanted;};
    
private:
    int number_1;
    int number_2;
    string calculationWanted;
};


class Chain{
public:
    void setNextChian(Chain* newChain){
        this->nextChian=newChain;
    };
    virtual void calculateNum(Numbers request)=0;
protected:
    Chain *nextChian;
};


class AddNumbers:public Chain{
public:
    void calculateNum(Numbers request);
};

void AddNumbers::calculateNum(Numbers request){
    if(request.getCalcumethod()=="add"){
        cout << request.getNumber1()+request.getNumber2();
    }else{
        nextChian->calculateNum(request);
    }
};

class SubtractNumbers:public Chain{
public:
    void calculateNum(Numbers request);
};

void SubtractNumbers::calculateNum(Numbers request){
    if(request.getCalcumethod()=="subtract"){
        cout << request.getNumber1()-request.getNumber2();
    }else{
        nextChian->calculateNum(request);
    };
};


class MultiNumbers:public Chain{
public:
    void calculateNum(Numbers request);
};

void MultiNumbers::calculateNum(Numbers request){
    if(request.getCalcumethod()=="multi"){
        cout << request.getNumber1()*request.getNumber2();
    }else{
        nextChian->calculateNum(request);
    };
};

class DivNumbers:public Chain{
public:
    void calculateNum(Numbers request);
};

void DivNumbers::calculateNum(Numbers request){
    if(request.getCalcumethod()=="divide"){
        cout << request.getNumber1()/request.getNumber2();
    }else{
        cout << "only works for + - * /" << endl;
    };
};

int main(int argc, const char * argv[]) {

    Chain *cur1=new AddNumbers();
    Chain *cur2=new SubtractNumbers();
    Chain *cur3=new MultiNumbers();
    Chain *cur4=new AddNumbers();
    Chain *cur5=new DivNumbers();
    
    cur1->setNextChian(cur2);
    cur2->setNextChian(cur3);
    cur3->setNextChian(cur4);
    cur4->setNextChian(cur5);

    cur1->calculateNum(Numbers(5,6,"multi"));
    cout << endl;
    return 0;
}
