//
//  Header.h
//  Animal
//
//  Created by Lihua Xu on 5/10/21.
//

#ifndef Header_h
#define Header_h

class Animal{
public:
    //constructor
    Animal()=default;
    
    void setName(std::string s){
        name=s;
    }
    std::string getName(){
        return name;
    }
    
    void setWeight(int w){
        if(w>0)weight=w;
        else{
            std::cerr<< "The weight must be larger than 0.";
            //throw "The weight must be larger than 0.";
        }
    }
    int getWeight(){
        return weight;
    }
    
    void setSound(std::string s){
        sound=s;
    }
    std::string getSound(){
        return sound;
    }

    
private:
    std::string name;
    int weight;
    std::string sound;
    
};


#endif /* Header_h */
