//
//  Animal.h
//  DesignPatterns
//
//  Created by Lihua Xu on 5/10/21.
//

#ifndef Animal_h
#define Animal_h
#include "Fly.h"
class Animal{
public:
    //constructor
    Animal()=default;
    
    void setName(std::string s){
        name=s;
    }
    std::string getName(){
        return name;
    }
    
    void setWeight(int w){
        if(w>0)weight=w;
        else{
            std::cerr<< "The weight must be larger than 0.";
            //throw "The weight must be larger than 0.";
        }
    }
    int getWeight(){
        return weight;
    }
    
    void setSound(std::string s){
        sound=s;
    }
    std::string getSound(){
        return sound;
    }
    
    void setflyType(Fly *newflyType){
        flyType=newflyType;
    }
    std::string tryToFly(){
        return flyType->fly();
    }
protected:
    Fly *flyType=nullptr;

private:
    
    std::string name;
    int weight;
    std::string sound;
    
};

#endif /* Animal_h */
