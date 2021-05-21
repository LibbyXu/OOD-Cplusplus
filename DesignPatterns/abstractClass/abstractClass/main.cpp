//
//  main.cpp
//  abstractClass
//
//  Created by Lihua Xu on 5/10/21.
//

#include <iostream>
#include <string>
#include "Creatures.h"
using namespace std;

class Giraffe:public creature{
public:
    void setSound(){
        sound="Memo";
    };
    void setWeight(int w){
        if(w>10)weight=w;
        else{
            throw runtime_error("The weight should be larger than 10 kg.");
        }
    };
};

int main(int argc, const char * argv[]) {
 
    creature* cur=new Giraffe;
    cur->setName("Lili");
    cur->setSound();
    //cur->setWeight(5);
    
    cout << cur->getName() << endl;
    cout << cur->getSound() << endl;
    //cout << cur->getWeight() << endl;
    
    return 0;
}
