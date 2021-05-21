//
//  RoketEnemyShip.h
//  factoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef RoketEnemyShip_h
#define RoketEnemyShip_h

#include "EnemyShip.h"
class RoketEnemyShip:public EnemyShip{
public:
    RoketEnemyShip(){
        setName("Roket Enemy Ship");
        setamtDamage(15.6);
    }
};

#endif /* RoketEnemyShip_h */
