//
//  ATMDATA.h
//  ProxyDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef ATMDATA_h
#define ATMDATA_h
class ATMState;

class GetATMData{
public:
    virtual void getATMData()=0;
    virtual int getCashInMachine()=0;
};

#endif /* ATMDATA_h */
