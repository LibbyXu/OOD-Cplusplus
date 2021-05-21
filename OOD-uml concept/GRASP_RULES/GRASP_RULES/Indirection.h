//
//  PureFabrications.h
//  GRASP_RULES
//
//  Created by Lihua Xu on 5/20/21.
//

#ifndef PureFabrications_h
#define PureFabrications_h
#include <string>


class EnemyAttacker{
public:
    virtual void attack()=0;
};

class EnemyTank:public EnemyAttacker{
public:
    void attack(){
        std::cout << "Tank fires 2 missiles." << std::endl;
    }
};

class EnemyRobot{
public:
    void jumpyOnEnemy(){
        std::cout << "Robot jumps on the enemy."<<std::endl;
    }
};

class EnemyRobotAdapter:public EnemyAttacker{
public:
    EnemyRobotAdapter(EnemyRobot* newRobot):theRobot(newRobot){}
    void attack(){
        theRobot->jumpyOnEnemy();
    }
private:
    EnemyRobot *theRobot;
};

#endif /* PureFabrications_h */
