//
//  main.cpp
//  DesignPatterns
//
//  Created by Lihua Xu on 5/10/21.
//

#include <iostream>
#include <string>
#include "Fly.h"
#include "Animal.h"
#include "Dog.h"
using namespace std;

int main(int argc, const char * argv[]) {

    Animal *dog=new Dog("meme","miaomiao",10);
    cout << dog->tryToFly() << endl;
    
    dog->setflyType(new ItFly);//Nice try
    cout << dog->tryToFly() << endl;
    
    return 0;
}
