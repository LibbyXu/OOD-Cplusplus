//
//  main.cpp
//  MementoDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Mementor{
public:
    Mementor(string newMementor){
        article=newMementor;
    };
    string getMementor(){return article;};
private:
    string article;
};

class Originator{
public:
    void setArtile(string newArticle){
        cout << "From Originator: Current version of article is: " << newArticle << endl;
        article=newArticle;
    };
    Mementor* storeInMementor(){
        cout << "From Originator: Saving to Memento" << endl;
        return new Mementor(article);
    };
    string restorFromMementor(Mementor* usedOne){
        article=usedOne->getMementor();
        cout << "From Originator: Previous article saved in Memento " << article << endl;
        return article;
    };
    
private:
    string article;
};

class CareTaker{
public:
    void Add(Mementor* newMementor){mementorList.push_back(newMementor);};
    void DeleteMementor(Mementor* newMementor){
        bool findOne=false;
        for(auto it=mementorList.begin();it!=mementorList.end();++it){
            if((*it)->getMementor()==newMementor->getMementor()){
                mementorList.erase(it);
                findOne=true;
            }
            if(findOne)break;
        };
        if(!findOne)cout << "We didn't find the corresponding mementor." << endl;
    };
    Mementor* getMementor(int index){
        if(index<mementorList.size())return mementorList[index];
        cout << "We didn't find the menmentor." << endl;
        return nullptr;
    };
    void getMementorList(){
        cout << "The mementor List is :\n";
        for(auto it=mementorList.cbegin();it!=mementorList.cend();++it){
            cout << (*it)->getMementor() << endl;
        }
    };
private:
    vector<Mementor*> mementorList;
};



int main(int argc, const char * argv[]) {
  
    Originator* cur=new Originator;
    CareTaker *me=new CareTaker;
    
    cur->setArtile("I want apple.");
    me->Add(cur->storeInMementor());
    cur->setArtile("I want a pen.");
    me->Add(cur->storeInMementor());
    cur->setArtile("I want a pineapple.");
    me->Add(cur->storeInMementor());
    
    Mementor* used1=me->getMementor(1);
    Mementor* used2=me->getMementor(2);
    
    me->DeleteMementor(used1);
    me->DeleteMementor(used2);
    
    cur->restorFromMementor(used1);
    me->Add(cur->storeInMementor());
    
    me->getMementorList();
    
    //对于指针 erase并没有释放空间，需要用delete释放空间
    //当然程序结束之后，调用解析函数，会自动释放空间
    
    return 0;
}
