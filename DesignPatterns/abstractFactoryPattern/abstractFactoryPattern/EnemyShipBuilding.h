//
//  EnemyShipBuilding.h
//  abstractFactoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef EnemyShipBuilding_h
#define EnemyShipBuilding_h
#include "EnemyShip.h"
#include "enemyShipFactory.h"
class EnemyShipBuilding{
public:
    virtual EnemyShip* makeEnemyShip(std::string typeOfShip)=0;
    
    EnemyShip* orderTheShip(std::string typeOfShip){
        EnemyShip *theEnemyShip = makeEnemyShip(typeOfShip);
        theEnemyShip->displayEnemyShip();
        
        return theEnemyShip;
    }
};

class UFOEnemyShipBuilding:public EnemyShipBuilding{
public:
    
    EnemyShip* makeEnemyShip(std::string typeOfShip){
        EnemyShip *theEnemyShip=nullptr;
        
        if(typeOfShip=="UFO"){
            EnemyShipFactory *shipPartsFactory=new UFOEnemyShipFactory();
            theEnemyShip=new UFOEnemyShip(shipPartsFactory);
            theEnemyShip->setName("UFO Grunt Ship");
        }else if(typeOfShip=="UFO BOSS"){
            EnemyShipFactory *shipPartsFactory=new UFOBossEnemyShipFactory();
            theEnemyShip=new UFOBossEnemyShip(shipPartsFactory);
            theEnemyShip->setName("UFO Boss Ship");
        }
        
        return theEnemyShip;
    };
};

#endif /* EnemyShipBuilding_h */
