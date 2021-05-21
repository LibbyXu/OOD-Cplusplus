//
//  main.cpp
//  BuilderDesignParttern
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
using namespace std;

class RobotPlan{
public:
    virtual void setRobotHead(string head)=0;
    virtual void setRobotTorso(string torso)=0;
    virtual void setRobotArms(string arms)=0;
    virtual void setRobotLegs(string legs)=0;
    string getRobotHead(){
        return robotHead;
    };
    string getRobotTorso(){
        return robotTorso;
    };
    string getRobotArms(){
        return robotArms;
    };
    string getRobotLegs(){
        return robotLegs;
    };
protected:
    string robotHead;
    string robotTorso;
    string robotArms;
    string robotLegs;
};

class Robot:public RobotPlan{
public:
    void setRobotHead(string head){
        robotHead=head;
    };
    void setRobotTorso(string torso){
        robotTorso=torso;
    };
    void setRobotArms(string arms){
        robotArms=arms;
    };
    void setRobotLegs(string legs){
        robotLegs=legs;
    };
};

class RobotBuilder{
public:
    virtual void buildRobotHead()=0;
    virtual void buildRobotTorso()=0;
    virtual void buildRobotArms()=0;
    virtual void buildRobotLegs()=0;
    Robot* getRobot(){
        return robot;
    };
protected:
    Robot *robot;
};

class OldRobotBuilder:public RobotBuilder{
public:
    OldRobotBuilder(){
        this->robot=new Robot();
    };
    void buildRobotHead(){
        robot->setRobotHead("Tin Head");
    };
    void buildRobotTorso(){
        robot->setRobotTorso("Tin Torso");
    };
    void buildRobotArms(){
        robot->setRobotArms("Tin Arms");
    };
    void buildRobotLegs(){
        robot->setRobotLegs("Tin Legs");
    };
};

class RobotEngineer{
public:
    RobotEngineer(RobotBuilder *robotBuilder){
        this->robotBuilder=robotBuilder;
    };
    Robot* getRobot(){
        return this->robotBuilder->getRobot();
    };
    void makeRobot(){
        this->robotBuilder->buildRobotHead();
        this->robotBuilder->buildRobotTorso();
        this->robotBuilder->buildRobotArms();
        this->robotBuilder->buildRobotLegs();
    };
private:
    RobotBuilder *robotBuilder;
};

int main(int argc, const char * argv[]) {
    
    RobotBuilder *oldStyleRobot=new OldRobotBuilder();
    
    RobotEngineer *RE=new RobotEngineer(oldStyleRobot);
    
    RE->makeRobot();
    Robot *firstRobot=RE->getRobot();
    
    cout << "This robot is built:" << endl;
    
    cout << firstRobot->getRobotHead() << endl;
    cout << firstRobot->getRobotTorso() << endl;
    cout << firstRobot->getRobotArms() << endl;
    cout << firstRobot->getRobotLegs() << endl;
    
    return 0;
}
