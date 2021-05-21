//
//  Polymorphism.h
//  GRASP_RULES
//
//  Created by Lihua Xu on 5/20/21.
//

#ifndef Polymorphism_h
#define Polymorphism_h
#include <string>

class GetSilverPrice{
public:
    virtual double getPriceSilver()=0;
    virtual std::string getName()=0;
};

class ABSSilver:public GetSilverPrice{
private:
    std::string silverPrice="SLV 30.66";
    std::string name="ABC Silver";
public:
    double getPriceSilver(){
        std::string strPrice=silverPrice;
        size_t m=strPrice.find_last_of(" ");
        return stod(strPrice.substr(m+1));
    }
    std::string getName(){
        return name;
    }
};

class XYZSilver:public GetSilverPrice{
private:
    std::string silverPrice="36.66 for silver";
    std::string name="XYZ Silver";
public:
    double getPriceSilver(){
        std::string strPrice=silverPrice;
        size_t m=strPrice.find_first_of(" ");
        return stod(strPrice.substr(0,m+1));
    }
    std::string getName(){
        return name;
    }
};
#endif /* Polymorphism_h */
