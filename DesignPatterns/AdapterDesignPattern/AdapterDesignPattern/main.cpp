//
//  main.cpp
//  AdapterDesignPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
#include <random>
using namespace std;

class EnemyRobot{
public:
    void smashWithHands(){
        int attackerDamage=rand()%60;
        cout << "Enemy Robot attack does " << attackerDamage << " damage." << endl;
    };
    void walkForward(){
        movement=rand()%10;
        cout << "Enemy Robot movemont is " << movement << endl;
    };
    void putDriver(string driver){
        CurDriver=driver;
        cout << "Enemy Robot driver is " << CurDriver << endl;
    };
private:
    int attackerDamage;
    int movement;
    string CurDriver;
};

class EnemyAttacker{
public:
    virtual void fireWeapon()=0;
    virtual void driveForward()=0;
    virtual void assignDriver(string driver)=0;
};

class EnemyRobotAdapter:public EnemyAttacker{
public:
    EnemyRobotAdapter(EnemyRobot *newRobot){
        theRobot=newRobot;
    };
    void fireWeapon(){
        theRobot->smashWithHands();
    };
    void driveForward(){
        theRobot->walkForward();
    };
    void assignDriver(string driver){
        theRobot->putDriver(driver);
    };
private:
    EnemyRobot *theRobot;
};

class EnemyTank:public EnemyAttacker{
public:
    void fireWeapon(){
        int attackerDamage=rand()%60;
        cout << "Enemy Tank attack does " << attackerDamage << " damage." << endl;
    };
    void driveForward(){
        int movement=rand()%10;
        cout << "Enemy Tank movemont is " << movement << endl;
    };
    void assignDriver(string driver){
        string CurDriver=driver;
        cout << "Enemy Tank driver is " << CurDriver << endl;
    };

};

int main(int argc, const char * argv[]) {
    EnemyTank *rx7Tank=new EnemyTank();
    
    EnemyRobot *fredTheRobot = new EnemyRobot();
    
    EnemyAttacker *robot=new EnemyRobotAdapter(fredTheRobot);
    
    cout << "The Robot has been created successfully." << endl;
    
    robot->assignDriver("Paul");
    robot->fireWeapon();
    robot->driveForward();
    
    return 0;
}
