//
//  main.cpp
//  VirtualFunctionw
//
//  Created by Lihua Xu on 5/10/21.
//

#include <iostream>
#include <string>
using namespace std;

/*
class Instrument{
public:
    void MakeSound(){
        cout <<  "Instrument playing...\n";
    }
};

class Accordion:public Instrument{
public:
    void MakeSound(){
        cout << "Accordion Playing...\n";
    }
}
*/

class Instrument{//abstract class
public:
    virtual void MakeSound()=0;
};

class Accordion:public Instrument{
public:
    void MakeSound(){
        cout<< "Accordion playing...\n";
    }
};

class piano:public Instrument{
public:
    void MakeSound(){
        cout<< "Piano playing...\n";
    }
};


int main(int argc, const char * argv[]) {
    
    Instrument *i1;//abstract class allow the pointer
    i1=new Accordion();
    i1->MakeSound();
    
    Accordion i2;
    i2.MakeSound();
    
    Instrument *i3=new piano;
    
    Instrument* instruments[2]={i1,i3};
    for(int i=0;i<2;++i)instruments[i]->MakeSound();
    return 0;
}
