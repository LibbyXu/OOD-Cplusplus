//
//  weaponEngine.h
//  abstractFactoryPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#ifndef weaponEngine_h
#define weaponEngine_h

class ESWeapon{
public:
    virtual std::string toString()=0;
};

class ESEngine{
public:
    virtual std::string toString()=0;
};

class ESUFOGun:public ESWeapon{
public:
    std::string toString(){
        return "20 damage";
    };
};

class ESUFOEngine:public ESEngine{
public:
    std::string toString(){
        return "1000 mph";
    };
};

class ESUFOBossGun:public ESWeapon{
public:
    std::string toString(){
        return "40 damage";
    };
};

class ESUFOBossEngine:public ESEngine{
public:
    std::string toString(){
        return "2000 mph";
    };
};

#endif /* weaponEngine_h */
