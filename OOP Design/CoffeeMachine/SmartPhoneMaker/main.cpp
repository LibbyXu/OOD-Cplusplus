//
//  main.cpp
//  CoffeeMachine
//
//  Created by Lihua Xu on 5/10/21.
//

#include <iostream>
#include <string>
using namespace std;

//abstract class (no instant object but pointer)
class SmartPhone{
public:
    virtual void TakeASelfie()=0;
    virtual void MakeCall()=0;
};

class Android:public SmartPhone{
public:
    void TakeASelfie(){
        cout << "Android Selfie." << endl;
    }
    void MakeCall(){
        cout << "Android call." << endl;
    }
};

class Iphone:public SmartPhone{
public:
    void TakeASelfie(){
        cout << "Iphone Selfie." << endl;
    }
    void MakeCall(){
        cout << "Iphone call." << endl;
    }
};

int main(int argc, const char * argv[]) {
    SmartPhone* s1=new Android;
    s1->TakeASelfie();
    s1->MakeCall();
    SmartPhone* s2=new Iphone;
    s2->TakeASelfie();
    s2->MakeCall();
    return 0;
}
