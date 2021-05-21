//
//  EnemyShip.h
//  abstractFactoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef EnemyShip_h
#define EnemyShip_h
#include "weaponEngine.h"

class EnemyShip{
public:
    std::string getName(){
        return name;
    }
    void setName(std::string nm){
        name=nm;
    }
    
    std::string toString(){
        std::string infoOfShip="The "+ name + " has a top speed of " + engine->toString() + " and an attack power of " + weapon->toString();
        return infoOfShip;
    }
    
    void displayEnemyShip(){
        std::cout << toString() << std::endl;
    }
    
protected:
    ESWeapon *weapon;
    ESEngine *engine;
    
private:
    std::string name;
};

class UFOEnemyShip:public EnemyShip{
public:
    UFOEnemyShip(EnemyShipFactory* parts){
        this->weapon=parts->addESWeapon();
        this->engine=parts->addESEngine();
    };
};

class UFOBossEnemyShip:public EnemyShip{
public:
    UFOBossEnemyShip(EnemyShipFactory* parts){
        this->weapon=parts->addESWeapon();
        this->engine=parts->addESEngine();
    };
};


#endif /* EnemyShip_h */
