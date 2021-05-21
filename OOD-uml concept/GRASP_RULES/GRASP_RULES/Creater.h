//
//  Creater.h
//  GRASP_RULES
//
//  Created by Lihua Xu on 5/20/21.
//

#ifndef Creater_h
#define Creater_h
#include <string>

class Frame{
public:
   Frame(int newLength):length(newLength){}
private:
   int length;
};

class Wheel{
public:
   Wheel(int newWidth):width(newWidth){}
private:
   int width;
};

class Bike{
public:
    Bike(Wheel newWheel, Frame newFrame):theWheel(newWheel),theFrame(newFrame){}
    Bike(int newWheel, int newFrame):theWheel(Wheel(newWheel)),theFrame(Frame(newFrame)){}//The creater parttern want you to use this style more often

private:
    Wheel theWheel;
    Frame theFrame;
};



#endif /* Creater_h */
