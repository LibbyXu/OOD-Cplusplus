//
//  Fly.h
//  DesignPatterns
//
//  Created by Lihua Xu on 5/10/21.
//

#ifndef Fly_h
#define Fly_h

class Fly{
public:
    virtual std::string fly()=0;
};

class ItFly:public Fly{
public:
    std::string fly(){
        return "It can fly!";
    }
};

class ItCannotFly:public Fly{
public:
    std::string fly(){
        return "It cannot fly!";
    }
};

#endif /* Fly_h */
