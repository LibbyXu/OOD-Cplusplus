//
//  Dog.h
//  DesignPatterns
//
//  Created by Lihua Xu on 5/10/21.
//

#ifndef Dog_h
#define Dog_h
#include "Animal.h"
class Dog:public Animal{
public:
    Dog()=default;
    Dog(std::string name,std::string sound,int w){
        this->setName(name);
        this->setSound(sound);
        this->setWeight(w);
        this->flyType=new ItCannotFly;
    };
    void digHole(){
        std::cout << "Dug a hole." << std::endl;
    }
    
};

#endif /* Dog_h */
