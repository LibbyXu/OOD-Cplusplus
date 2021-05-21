//
//  Creatures.h
//  abstractClass
//
//  Created by Lihua Xu on 5/10/21.
//

#ifndef Creatures_h
#define Creatures_h
class creature{
public:
    virtual void setName(std::string s){
        name=s;
    };
    virtual void setSound()=0;
    virtual void setWeight(int)=0;
    
    std::string getName(){
        return name;
    }
    std::string getSound(){
        return sound;
    }
    int getWeight(){
        return weight;
    }
protected:
    std::string name;
    int weight;
    std::string sound;
};

#endif /* Creatures_h */
