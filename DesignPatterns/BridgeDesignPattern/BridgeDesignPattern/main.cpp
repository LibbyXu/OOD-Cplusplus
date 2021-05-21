//
//  main.cpp
//  BridgeDesignPattern
//
//  Created by Lihua Xu on 5/12/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class EntertainmentDevice{
protected:
    int deviceState;
    int maxSetting;
    int volumnSetting=0;

public:
    virtual void buttonFivePress()=0;
    virtual void buttonSixPress()=0;
    virtual void deviceFeedback(){
        if(deviceState>maxSetting || deviceState<0){
            deviceState=0;
        }
        cout << "On " << deviceState << endl;
    };
    void buttonSevenPress(){
        volumnSetting++;
        cout << "The current volumn level is " << volumnSetting << endl;
    };
    void buttonEightPress(){
        volumnSetting--;
        cout << "The current volumn level is " << volumnSetting << endl;
    };
};

class TVDevice:public EntertainmentDevice{
public:
    TVDevice(int newDeviceState, int newMaxSetting){
        deviceState=newDeviceState;
        maxSetting=newMaxSetting;
    };
    void buttonFivePress(){
        cout << "Channel down." << endl;
        deviceState--;
    };
    void buttonSixPress(){
        cout << "Channel up." << endl;
        deviceState++;
    };
};


class RemoteButtons{
protected:
    EntertainmentDevice *Device=nullptr;
public:
    void buttonFivePressed(){
        Device->buttonFivePress();
    };
    void buttonSixPressed(){
        Device->buttonSixPress();
    };
    void deviceFeedback(){
        Device->deviceFeedback();
    };
    virtual void buttonNinePressed()=0;
};

class TvRemoteMute:public RemoteButtons{
public:
    TvRemoteMute(EntertainmentDevice *newDevice){
        Device=newDevice;
    };
    void buttonNinePressed(){
        cout << "Tv was Muted" << endl;
    };
};

class TvRemotePause:public RemoteButtons{
public:
    TvRemotePause(EntertainmentDevice *newDevice){
        Device=newDevice;
    };
    void buttonNinePressed(){
        cout << "Tv was Paused" << endl;
    };
};

int main(int argc, const char * argv[]) {
 
    EntertainmentDevice *cur= new TVDevice(10,4);
    RemoteButtons *curButtonMute=new TvRemoteMute(cur);
    RemoteButtons *curButtonPause=new TvRemotePause(cur);
    
    curButtonMute->buttonNinePressed();
    curButtonMute->buttonFivePressed();
    curButtonMute->buttonSixPressed();
    
    curButtonPause->buttonNinePressed();
    curButtonPause->buttonFivePressed();
    curButtonPause->buttonSixPressed();
    curButtonPause->deviceFeedback();
    
    return 0;
}
