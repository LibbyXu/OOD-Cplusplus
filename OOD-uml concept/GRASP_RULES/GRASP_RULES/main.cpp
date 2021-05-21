//
//  main.cpp
//  GRASP_RULES
//
//  Created by Lihua Xu on 5/20/21.
//

#include <iostream>
#include <vector>
#include "Creater.h"
#include "LowCoupling.h"
#include "Polymorphism.h"
#include "Indirection.h"
using namespace std;

int main(int argc, const char * argv[]) {
    //-------------------------------------------
    //Creater
    Wheel *wheel=new Wheel(10);
    Frame *frame=new Frame(15);
    Wheel wheel1(4);
    Frame frame1(12);
    Bike *bike1=new Bike(*wheel,*frame);
    Bike bike2(*wheel,*frame);
    Bike bike3(wheel1,frame1);

    //The creater want you to use the following partterns more often code is clean and easy
    Bike bike4(67,23);
    Bike *bike5=new Bike(34,56);
    
    delete wheel;
    delete frame;
    delete bike1;
    delete bike5;

    //-------------------------------------------
    //High Coupling
    Monkey monkey("Justin");
    Lion lion("Leao");
    
    ListAnimals listAnimal(monkey,lion);
    listAnimal.displayAnimals();
    // if we want to add more sorts of animals, it is bad it will increase the coding works
    
    //Low Coupling
    Animal *monkey1=new Monkey2("GHASGD");
    Animal *lion1=new Lion2("opegwgq");
    Animal *monkey2=new Monkey2("uywqwf");
    
    ListAnimals2* cur=new ListAnimals2;
    cur->addAnimal(monkey1);
    cur->addAnimal(lion1);
    cur->addAnimal(monkey2);
    cur->displayAnimalName();
    
    //-------------------------------------------
    //Polymorphism
    vector<GetSilverPrice*>silverSeller;
    
    silverSeller.push_back(new XYZSilver);
    silverSeller.push_back(new ABSSilver);

    for(auto iter=silverSeller.cbegin();iter!=silverSeller.cend();++iter){
        cout << (*iter)->getName() << " " << (*iter)->getPriceSilver() << endl;
    }

    //Indirection
    
    EnemyAttacker *theTank=new EnemyTank();
    EnemyRobot *theRobot=new EnemyRobot();
    EnemyRobotAdapter *robotAttacker=new EnemyRobotAdapter(theRobot);
    
    theTank->attack();
    robotAttacker->attack();
    
    
    return 0;
}
