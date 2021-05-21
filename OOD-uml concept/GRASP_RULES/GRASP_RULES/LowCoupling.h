//
//  owCoupling.h
//  GRASP_RULES
//
//  Created by Lihua Xu on 5/20/21.
//

#ifndef LowCoupling_h
#define LowCoupling_h
#include <string>
#include <vector>

//High coupling situation
class Monkey{
public:
    Monkey(std::string newName):name(newName){}
    std::string call(){return "Monkey named "+name;}
private:
    std::string name;
};

class Lion{
public:
    Lion(std::string newName):name(newName){}
    std::string call(){return "Lion named "+name;}
private:
    std::string name;
};

class ListAnimals{
public:
    ListAnimals(Monkey newMonkey, Lion newLion):theMonkey(newMonkey),theLion(newLion){}
    void displayAnimals(){
        std::cout << theMonkey.call() << std::endl;
        std::cout << theLion.call() << std::endl;
    }
private:
    Monkey theMonkey;
    Lion theLion;
};


//Low Coupling

class Animal{
public:
    Animal(std::string newName):Name(newName){}
    virtual std::string displayAnimal()=0;
    std::string getName(){return Name;}
private:
    std::string Name;
};

class Monkey2:public Animal{
public:
    Monkey2(std::string newName):Animal(newName){}
    std::string displayAnimal(){
        return "Monkey2 named "+getName();
    }
};

class Lion2:public Animal{
public:
    Lion2(std::string newName):Animal(newName){}
    std::string displayAnimal(){
        return "Lion2 named "+ getName();
    }
};

class ListAnimals2{
public:
    ListAnimals2()=default;
    void addAnimal(Animal *c){
        theAnimals.push_back(c);
    }
    void displayAnimalName(){
        for(auto iter=theAnimals.cbegin();iter!=theAnimals.cend();++iter){
            std::cout << (*iter)->displayAnimal() << std::endl;
        }
    }
private:
    std::vector<Animal*>theAnimals;
};


#endif /* LowCoupling_h */
