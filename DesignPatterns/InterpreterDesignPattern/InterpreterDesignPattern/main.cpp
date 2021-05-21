//
//  main.cpp
//  InterpreterDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class ConversionContext{
public:
    string getInput(){return conversionQues;};

    string getFromConversion(){
        return fromConversion;
    };
    
    string gettoConversion(){
        return toConversion;
    };
    
    string getResponse(){
        return conversionResponse;
    };
    
    double getQuantity(){
        return quantity;
    };
    
    ConversionContext(string newCoversionQues):conversionQues(newCoversionQues){
        stringstream whole(getInput());
        string s;
        while(getline(whole,s,' ')){
            if(s.length()){
                partsOfQues.push_back(s);
            }
        }
        fromConversion=getCapitalized(partsOfQues[1]);
        toConversion=getLowercase(partsOfQues[3]);
        quantity=stod(partsOfQues[0]);
        conversionResponse=partsOfQues[0]+" "+partsOfQues[1]+" "+" equals ";
    };
private:
    string conversionQues;
    string conversionResponse;
    string fromConversion;
    string toConversion;
    double quantity;
    vector<string>partsOfQues;
    string getCapitalized(string s){
        for_each(s.begin(),s.end(),[](char &s){tolower(s);});
        s[0]=toupper(s[0]);
        
        int lenOfWord=static_cast<int>(s.length());
        
        if(s.at(lenOfWord-1)!='s'){
            s+='s';
        }
 
        return s;
    };
    
    string getLowercase(string s){
        for_each(s.begin(),s.end(),[](char &s){tolower(s);});
        int lenOfWord=static_cast<int>(s.length());
        
        if(s.at(lenOfWord-1)!='s'){
            s+='s';
        }
        return s;
    };
    
};

class Experssion{
public:
    virtual string gallons(double quantity)=0;
    virtual string quarts(double quantity)=0;
    virtual string pints(double quantity)=0;
    virtual string cups(double quantity)=0;
    virtual string tablespoons(double quantity)=0;
};

class Gallons:public Experssion{
public:
    string gallons(double quantity){
        return to_string(quantity);
    };
    string quarts(double quantity){
        quantity*=2;
        return to_string(quantity);
    };
    string pints(double quantity){
        quantity*=4;
        return to_string(quantity);
    };
    string cups(double quantity){
        quantity*=8;
        return to_string(quantity);
    };
    string tablespoons(double quantity){
        quantity*=16;
        return to_string(quantity);
    }
};

class Quarts:public Experssion{
public:
    string gallons(double quantity){
        quantity/=2;
        return to_string(quantity);
    };
    string quarts(double quantity){
        return to_string(quantity);
    };
    string pints(double quantity){
        quantity*=2;
        return to_string(quantity);
    };
    string cups(double quantity){
        quantity*=4;
        return to_string(quantity);
    };
    string tablespoons(double quantity){
        quantity*=8;
        return to_string(quantity);
    }
};

class Pints:public Experssion{
public:
    string gallons(double quantity){
        quantity/=4;
        return to_string(quantity);
    };
    string quarts(double quantity){
        quantity/=2;
        return to_string(quantity);
    };
    string pints(double quantity){
        return to_string(quantity);
    };
    string cups(double quantity){
        quantity*=2;
        return to_string(quantity);
    };
    string tablespoons(double quantity){
        quantity*=4;
        return to_string(quantity);
    }
};

class Cups:public Experssion{
public:
    string gallons(double quantity){
        quantity/=8;
        return to_string(quantity);
    };
    string quarts(double quantity){
        quantity/=4;
        return to_string(quantity);
    };
    string pints(double quantity){
        quantity/=2;
        return to_string(quantity);
    };
    string cups(double quantity){
        return to_string(quantity);
    };
    string tablespoons(double quantity){
        quantity*=2;
        return to_string(quantity);
    }
};

class Tablespoons:public Experssion{
public:
    string gallons(double quantity){
        quantity/=16;
        return to_string(quantity);
    };
    string quarts(double quantity){
        quantity/=8;
        return to_string(quantity);
    };
    string pints(double quantity){
        quantity/=4;
        return to_string(quantity);
    };
    string cups(double quantity){
        quantity/=2;
        return to_string(quantity);
    };
    string tablespoons(double quantity){
        
        return to_string(quantity);
    }
};


void findConverter(Experssion*& curob, const string fromConversion){
    if(fromConversion=="Gallons"){
        curob=new Gallons();
    }else if(fromConversion=="Pints"){
        curob=new Pints();
    }else if(fromConversion=="Tablespoons"){
        curob=new Tablespoons();
    }else if(fromConversion=="Cups"){
        curob=new Cups();
    }else if(fromConversion=="Quarts"){
        curob=new Quarts();
    }
};


string findDestinationConversion(Experssion* curob,const string toConversion, const double quanti){
    if(toConversion=="gallons"){
        return curob->gallons(quanti);
    }else if(toConversion=="pints"){
        return curob->pints(quanti);
    }else if(toConversion=="tablespoons"){
        return curob->tablespoons(quanti);
    }else if(toConversion=="cups"){
        return curob->cups(quanti);
    }else if(toConversion=="quarts"){
        return curob->quarts(quanti);
    }

    return string("Not defined!");
};

int main(int argc, const char * argv[]) {

    cout << "What is your question?" << endl;
    
    string ques;
    getline(cin,ques);
    
    ConversionContext *cur=new ConversionContext(ques);
    
    string input= cur->getInput();
    string fromConversion= cur->getFromConversion();
    string toConversion= cur->gettoConversion();
    double quanti= cur->getQuantity();
    
    cout << input << endl;
    cout << fromConversion << endl;
    cout << toConversion << endl;
    cout << quanti << endl;
    
//
    Experssion *curob;
    findConverter(curob, fromConversion);
    
//    if(fromConversion=="Gallons"){
//        curob=new Gallons;
//    }else if(fromConversion=="Pints"){
//        curob=new Pints;
//    }else if(fromConversion=="Tablespoons"){
//        curob=new Tablespoons;
//    }else if(fromConversion=="Cups"){
//        curob=new Cups;
//    }else if(fromConversion=="Quarts"){
//        curob=new Quarts;
//    }
//
//
//
//    if(!curob)return -1;
//    string convertedQuanti;
//
//    if(toConversion=="gallons"){
//        convertedQuanti=curob->gallons(quanti);
//    }else if(toConversion=="pints"){
//        convertedQuanti=curob->pints(quanti);
//    }else if(toConversion=="tablespoons"){
//        convertedQuanti=curob->tablespoons(quanti);
//    }else if(toConversion=="cups"){
//        convertedQuanti=curob->cups(quanti);
//    }else if(toConversion=="quarts"){
//        convertedQuanti=curob->quarts(quanti);
//    }

    string convertedQuanti=findDestinationConversion(curob,toConversion,quanti);
    
    
    cout << cur->getResponse()<< convertedQuanti << " " << toConversion << endl;
    
    return 0;
}
