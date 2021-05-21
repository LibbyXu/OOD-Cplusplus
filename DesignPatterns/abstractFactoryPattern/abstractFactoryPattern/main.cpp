//
//  main.cpp
//  abstractFactoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
#include "weaponEngine.h"
#include "enemyShipFactory.h"
#include "EnemyShip.h"
#include "EnemyShipBuilding.h"
using namespace std;


int main(int argc, const char * argv[]) {

    EnemyShipBuilding *MakeUFOs =  new UFOEnemyShipBuilding;
    EnemyShip *theGrant=MakeUFOs->orderTheShip("UFO");
    EnemyShip *theBoss=MakeUFOs->orderTheShip("UFO BOSS");
    
    return 0;
}
