//
//  main.cpp
//  Animal
//
//  Created by Lihua Xu on 5/10/21.
//

#include <iostream>
#include <string>
#include "Header.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

void changeObjectName(Dog *fido){
    fido->setName("Marcus");
}

//int *a = new int; a is pointing to default-initialized object (which is uninitialized object in this case i.e the value is indeterminate as per the Standard). int *a = new int(); a is pointing to value-initialized object (which is zero-initialized object in this case i.e the value is zero as per the Standard).

int main(int argc, const char * argv[]) {
    
    Animal* cat=new Cat;
    cat->setName("Mimi");
    cat->setSound("Miao");
    cat->setWeight(20);
    cout << cat->getName() << ' ' << cat->getSound() << ' ' << cat->getWeight()<< endl;
    
    Dog* dog=new Dog();
    dog->setName("Taorao");
    dog->setSound("Wong");
    dog->setWeight(16);
    dog->digHole();
    changeObjectName(dog);
    
    cout << dog->getName() << ' ' << dog->getSound() << ' ' << dog->getWeight()<< endl;
    
    return 0;
}
