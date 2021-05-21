//
//  main.cpp
//  YoutubChannel
//
//  Created by Lihua Xu on 5/10/21.

#include <iostream>
#include <string>
#include <list>
using namespace std;

class youtubChannel{
public:
    youtubChannel(string name, string ownerName):Name(name),ownerName(ownerName),contentQuality(0){};
    void Subscribe(){
        subscriberCount++;
    }
    void unSubscribe(){
        if(subscriberCount>0)subscriberCount--;
    }
    void addVedioTitle(string s){
        PublishedVideoTitles.push_back(s);
    }
    string getName(){
        return Name;
    }
    string getOwnerName(){
        return ownerName;
    }
    int getSubscriberNum(){
        return subscriberCount;
    }
    list<string> getPublishedVedioTitle(){
        return PublishedVideoTitles;
    }
    bool isEmptyVedioList(){
        return PublishedVideoTitles.size()==0;
    }
    void getInfo(){
        cout << "Name: " << Name << endl;
        cout << "Onwer of the channel: " << ownerName << endl;
        cout << "The total subscriber number is: " << subscriberCount << endl;
        cout << "Vedios: " << endl;
        for(const auto &s: PublishedVideoTitles){
            cout << "   " << s << endl;
        }
        cout << endl;
    }
    void checkAnalytics(){
        if(contentQuality<5){
            cout << Name << " has bad quality content." << endl;
        }else{
            cout << Name << " has great content. " << endl;
        }
    }
private:
    string Name;
    int subscriberCount=0;
    list<string>PublishedVideoTitles;//a list of the vedios
protected:
    string ownerName;
    int contentQuality;
};


class cookingYoutubChannel:public youtubChannel{
public:
    cookingYoutubChannel(string name, string ownerName):youtubChannel(name,ownerName){};
    void practice(){
        cout << ownerName << " Practice cooking" << endl;
        contentQuality++;
    }
};

class singerYoutubChannel:public youtubChannel{
public:
    singerYoutubChannel(string name, string ownerName):youtubChannel(name,ownerName){};
    void practice(){
        cout << ownerName << " Practice singing" << endl;
        contentQuality++;
    }
};
int main(int argc, const char * argv[]) {
 
    youtubChannel ytChannel1("LIBBY","libby");
    ytChannel1.Subscribe();
    ytChannel1.Subscribe();
    ytChannel1.addVedioTitle("C++ LEARNING");
    ytChannel1.addVedioTitle("C++ LEARNING OOP");
    ytChannel1.getInfo();
        
    youtubChannel ytChannel2("Lily","lChao");
    ytChannel2.addVedioTitle("C++ LEARNING ccc");
    ytChannel2.getInfo();
    
    cookingYoutubChannel ytChannel3("Emily","Emma");
    ytChannel3.addVedioTitle("Cooking cookies");
    ytChannel3.Subscribe();
    ytChannel3.Subscribe();
    ytChannel3.getInfo();
    ytChannel3.practice();
    
    singerYoutubChannel ytChannel4("Lian","Cici");
    ytChannel4.addVedioTitle("adncing happyly");
    ytChannel4.Subscribe();
    ytChannel4.Subscribe();
    ytChannel4.getInfo();
    ytChannel4.practice();
    ytChannel4.practice();
    ytChannel4.practice();
    ytChannel4.practice();
    ytChannel4.practice();
    ytChannel4.checkAnalytics();
    
    youtubChannel* yt1= &ytChannel3;
    youtubChannel* yt2= &ytChannel4;
    
    yt1->checkAnalytics();
    yt2->checkAnalytics();
    
    return 0;
}
