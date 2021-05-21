//
//  Functions.h
//  factoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef Functions_h
#define Functions_h
#include "EnemyShip.h"
void doStuffEnemy(EnemyShip *cur){
    cur->displayEnemyShip();
    cur->followHeroShip();
    cur->EnemyShipShoots();
}

#endif /* Functions_h */
