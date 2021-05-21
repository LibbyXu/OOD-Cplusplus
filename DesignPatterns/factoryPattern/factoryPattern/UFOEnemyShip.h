//
//  UFOEnemyShip.h
//  factoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef UFOEnemyShip_h
#define UFOEnemyShip_h
#include "EnemyShip.h"
class UFOEnemyShip:public EnemyShip{
public:
    UFOEnemyShip(){
        setName("UFO Enemy Ship");
        setamtDamage(20.0);
    }
};


#endif /* UFOEnemyShip_h */
