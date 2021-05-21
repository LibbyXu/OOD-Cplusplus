//
//  main.cpp
//  factoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
#include "EnemyShip.h"
#include "UFOEnemyShip.h"
#include "BigUFOEnemyShip.h"
#include "RoketEnemyShip.h"
#include "EnemyShipFactory.h"
#include "Functions.h"
using namespace std;

int main(int argc, const char * argv[]) {

    EnemyShip *ufoShip= new UFOEnemyShip();
    doStuffEnemy(ufoShip);
    
    string enemyShipOption;
    
    cout << "What type of the ship? (U / R / B)" << endl;
    getline(cin,enemyShipOption);
    
//    if(enemyShipOption=="U"){
//        EnemyShip *theEnemyShip= new UFOEnemyShip();
//        doStuffEnemy(theEnemyShip);
//    }else{
//        EnemyShip *theEnemyShip= new RoketEnemyShip();
//        doStuffEnemy(theEnemyShip);
//    }
    EnemyShipFactory makeShip;
    EnemyShip *theEnemyShip= makeShip.MakeEnemyShip(enemyShipOption);
    if(theEnemyShip!=nullptr)doStuffEnemy(theEnemyShip);
    return 0;
}
