//
//  Cat.h
//  Animal
//
//  Created by Lihua Xu on 5/10/21.
//

#ifndef Cat_h
#define Cat_h
#include "Header.h"
class Cat:public Animal{
public:
    Cat()=default;
    Cat(std::string name,std::string sound,int w){
        this->setName(name);
        this->setSound(sound);
        this->setWeight(w);
    };
};

#endif /* Cat_h */
