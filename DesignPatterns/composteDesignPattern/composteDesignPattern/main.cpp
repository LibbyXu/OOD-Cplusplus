//
//  main.cpp
//  composteDesignPattern
//
//  Created by Lihua Xu on 5/12/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class SongComponent{
public:
    virtual void add(SongComponent *newSongComponent)=0;
    virtual void remove(SongComponent *newSongComponent)=0;
    virtual SongComponent* getComponent(int ComponentIndex)=0;
    virtual string getSongName()=0;
    virtual string getBandName()=0;
    virtual int getSongReleaseYear()=0;
    virtual void displaySongInfo()=0;
};

class SongGroup:public SongComponent{
public:
    SongGroup(string newgroupName, string newgroupDes){
        groupName=newgroupName;
        groupDescription=newgroupDes;
    };
    string getGroupName(){
        return groupName;
    };
    string getGroupDes(){
        return groupDescription;
    };
    void add(SongComponent *newSongComponent){
        lists.push_back(newSongComponent);
    };
    
    void remove(SongComponent *newSongComponent){
        for(int i=0;i<lists.size();++i){
            if(lists[i]->getSongName()==newSongComponent->getSongName() && lists[i]->getBandName()==newSongComponent->getBandName()  && lists[i]->getSongReleaseYear()==newSongComponent->getSongReleaseYear()){
                lists.erase(lists.begin()+i);
                break;
            }
        }
    };
    SongComponent* getComponent(int ComponentIndex){
        if(ComponentIndex<lists.size())return lists[ComponentIndex];
        return nullptr;
    };
    void displaySongInfo(){
        cout << groupName << "and the description is: " << groupDescription << endl;
        
        for(const auto &s:lists){
            s->displaySongInfo();
        };
    };
    string getSongName(){return "It is a group.";};
    string getBandName(){return "It is a group, not a song.";};
    int getSongReleaseYear(){return -1;};
private:
    string groupName;
    string groupDescription;
    vector<SongComponent*>lists;
};

class Song:public SongComponent{
public:
    Song(string newSong, string newBandName, int yearRelease):songName(newSong),bandName(newBandName),yearReleased(yearRelease){};
    void add(SongComponent *newSongComponent){
        cout << "It is the song not a component group." << endl;
    };
    void remove(SongComponent *newSongComponent){
        cout << "It is the song not a component group." << endl;
    };
    
    SongComponent* getComponent(int ComponentIndex){
        return nullptr;
    };

    string getSongName(){
        return songName;
    };
    
    string getBandName(){
        return bandName;
    };
    
    int getSongReleaseYear(){
        return yearReleased;
    };
    
    void displaySongInfo(){
        cout << getSongName() << " " << getBandName() << " " << getSongReleaseYear()<< endl;
    };

private:
    string songName;
    string bandName;
    int yearReleased;

};

class DiscJ{
public:
    DiscJ(SongComponent *newList){
        songList=newList;
    };
    void getSongList(){
        songList->displaySongInfo();
    };
private:
    SongComponent *songList;
};

int main(int argc, const char * argv[]) {
 
    SongComponent *industrialMusic=new SongGroup("Industrial", "metal, hiphop, hot blood");
    
    SongComponent *RandBMusic=new SongGroup("R&B", "mild and beautiful");
    
    SongComponent *claasicalMusic=new SongGroup("classical", "piano, volin");
    
    industrialMusic->add(new Song("asjksdg","sajkdghksag",1987));
    industrialMusic->add(new Song("asjksasfddsdg","sajkdghksagfff",1997));
    industrialMusic->add(new Song("ajsg","123kdghksag",1967));
    
    industrialMusic->add(RandBMusic);
    
    RandBMusic->add(new Song("ksadf","125235", 2003));
    RandBMusic->add(new Song("ksadff","1qwe25235", 2013));
    
    claasicalMusic->add(RandBMusic);
    
    DiscJ *Lily=new DiscJ(industrialMusic);
    Lily->getSongList();
    
    
    return 0;
}
