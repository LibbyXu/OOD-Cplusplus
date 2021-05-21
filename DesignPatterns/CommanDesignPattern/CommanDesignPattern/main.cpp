//
//  main.cpp
//  CommanDesignPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
using namespace std;

class ElectricDevice{
public:
    virtual void on()=0;
    virtual void off()=0;
    virtual void volumnDown()=0;
    virtual void volumnUp()=0;
private:
    int volumn;
    bool onState;
};

class Television:public ElectricDevice{
public:
    Television():volumn(0),onState(true){};
    
    void on(){
        cout << "TV is on." << endl;
    };
    void off(){
        cout << "TV is off." << endl;
    };
    void volumnUp(){
        volumn++;
        cout << "TV volumn is at " << volumn << endl;
    };

    void volumnDown(){
        volumn--;
        cout << "TV volumn is at " << volumn << endl;
    };
    
private:
    int volumn;
    bool onState;
};

class Command{
public:
    virtual void execute()=0;
protected:
    ElectricDevice *theDevice;
};

class TurnTvOn:public Command{
public:
    TurnTvOn(ElectricDevice *newdevice){
        theDevice=newdevice;
    };
    void execute(){
        theDevice->on();
    };
};

class TurnTvOff:public Command{
public:
    TurnTvOff(ElectricDevice *newdevice){
        theDevice=newdevice;
    };
    void execute(){
        theDevice->off();
    };
};

class TurnTvUp:public Command{
public:
    TurnTvUp(ElectricDevice *newdevice){
        theDevice=newdevice;
    };
    void execute(){
        theDevice->volumnUp();
    };
};

class TurnTvDown:public Command{
public:
    TurnTvDown(ElectricDevice *newdevice){
        theDevice=newdevice;
    };
    void execute(){
        theDevice->volumnDown();
    };
};

class DeviceButton{
public:
    DeviceButton(Command *newCommand){
        theCommand=newCommand;
    };
    void press(){
        theCommand->execute();
    };
private:
    Command *theCommand;
};

class TvRemote{
public:
    static ElectricDevice* getDevice(){
        return new Television;
    };
};


int main(int argc, const char * argv[]) {
 
    ElectricDevice *newDevice=TvRemote::getDevice();
    
    TurnTvOn *onCommand = new TurnTvOn(newDevice);
    
    DeviceButton *onPressed=new DeviceButton(onCommand);
    
    onPressed->press();
    
    TurnTvOff *offCommand = new TurnTvOff(newDevice);
    
    DeviceButton *offPressed=new DeviceButton(offCommand);
    
    offPressed->press();
    
    return 0;
}
