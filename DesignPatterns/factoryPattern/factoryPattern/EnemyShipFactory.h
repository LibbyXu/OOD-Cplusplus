//
//  EnemyShipFactory.h
//  factoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef EnemyShipFactory_h
#define EnemyShipFactory_h
#include "EnemyShip.h"
class EnemyShipFactory{
public:
    EnemyShip* MakeEnemyShip(std::string newShipType){
        if(newShipType=="U"){
            return new UFOEnemyShip;
        }else if(newShipType=="R"){
            return new RoketEnemyShip;
        }else if(newShipType=="B"){
            return new BigUFOEnemyShip;
        }
        
        return nullptr;
    };
};

#endif /* EnemyShipFactory_h */
