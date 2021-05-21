//
//  enemyShipFactory.h
//  abstractFactoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef enemyShipFactory_h
#define enemyShipFactory_h
#include "weaponEngine.h"
class EnemyShipFactory{
public:
    virtual ESEngine* addESEngine()=0;
    virtual ESWeapon* addESWeapon()=0;
};

class UFOEnemyShipFactory:public EnemyShipFactory{
public:
    ESEngine* addESEngine(){
        return new ESUFOEngine;
    };
    ESWeapon* addESWeapon(){
        return new ESUFOGun;
    }
};

class UFOBossEnemyShipFactory:public EnemyShipFactory{
public:
    ESEngine* addESEngine(){
        return new ESUFOBossEngine;
    };
    ESWeapon* addESWeapon(){
        return new ESUFOBossGun;
    }
};

#endif /* enemyShipFactory_h */
