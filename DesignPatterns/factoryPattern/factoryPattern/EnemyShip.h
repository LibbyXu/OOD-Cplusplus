//
//  EnemyShip.h
//  factoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef EnemyShip_h
#define EnemyShip_h
#include <iostream>
#include <string>
class EnemyShip{
private:
    std::string name;
    double amtDamage;
public:
    std::string getName(){
        return name;
    }
    double getamtDamage(){
        return amtDamage;
    }
    void setName(std::string n){
        name=n;
    }
    void setamtDamage(double d){
        amtDamage=d;
    }
    
    void followHeroShip(){
        std::cout << getName() << " is following the hero" << std::endl;
    }
    void displayEnemyShip(){
        std::cout << getName() << " is on the screen" << std::endl;
    }
    void EnemyShipShoots(){
        std::cout << getName() << " attacks and does damage " << getamtDamage() <<std::endl;
    }
};

#endif /* EnemyShip_h */
