//
//  BigUFOEnemyShip.h
//  factoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef BigUFOEnemyShip_h
#define BigUFOEnemyShip_h
#include "EnemyShip.h"
class BigUFOEnemyShip:public EnemyShip{
public:
    BigUFOEnemyShip(){
        setName("Big UFO Enemy Ship");
        setamtDamage(40.0);
    }
};

#endif /* BigUFOEnemyShip_h */
