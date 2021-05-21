//
//  main.cpp
//  IteratorDesignPattern
//
//  Created by Lihua Xu on 5/12/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;




class SongInfo{
public:
    SongInfo(string newSong, string newBandName, int yearRelease):songName(newSong),bandName(newBandName),yearReleased(yearRelease){};
    
    string getSongName(){
        return songName;
    };
    
    string getBandName(){
        return bandName;
    };
    
    int getYearReleased(){
        return yearReleased;
    };
private:
    string songName;
    string bandName;
    int yearReleased;
};

class SongIterator{
public:
    virtual vector<SongInfo*> getSongList()=0;
};

class Songof70s:public SongIterator{
public:
    Songof70s(){
        
        song70sList.resize(100);
        currentNum=0;
    };
    
    void addSong(string name, string bandname, int year){
        SongInfo *cur=new SongInfo(name,bandname,year);
        song70sList[currentNum++]=cur;
    };
    
    vector<SongInfo*> getSongList(){
        vector<SongInfo*>res=song70sList;
        song70sList.resize(currentNum);
        return song70sList;
    };

private:
    vector<SongInfo*>song70sList;
    int currentNum;
};

class Songof80s:public SongIterator{
public:
    Songof80s(){
        
        song80sList.resize(100);
        currentNum=0;
    };
    
    void addSong(string name, string bandname, int year){
        SongInfo *cur=new SongInfo(name,bandname,year);
        song80sList[currentNum++]=cur;
    };
    
    vector<SongInfo*> getSongList(){
        vector<SongInfo*>res=song80sList;
        song80sList.resize(currentNum);
        return song80sList;
    };

private:
    vector<SongInfo*>song80sList;
    int currentNum;
};

class Songof90s:public SongIterator{
public:
    Songof90s(){
        
        song90sList.resize(100);
        currentNum=0;
    };
    
    void addSong(string name, string bandname, int year){
        SongInfo *cur=new SongInfo(name,bandname,year);
        song90sList[currentNum++]=cur;
    };
    
    vector<SongInfo*> getSongList(){
        vector<SongInfo*>res=song90sList;
        song90sList.resize(currentNum);
        return song90sList;
    };

private:
    vector<SongInfo*>song90sList;
    int currentNum;
};

class diskDriver{
public:
    diskDriver(SongIterator *newsong70s, SongIterator *newsong80s, SongIterator *newsong90s){
        song70s=newsong70s;
        song80s=newsong80s;
        song90s=newsong90s;
    };
    
    void showList(){
        vector<SongInfo*>song70=song70s->getSongList();
        vector<SongInfo*>song80=song80s->getSongList();
        vector<SongInfo*>song90=song90s->getSongList();
        
        cout << "70s Song list: " << endl;
        showInfoSong(song70);
        
        cout << "\n80s Song list: " << endl;
        showInfoSong(song80);
        
        cout << "\n90s Song list: " << endl;
        showInfoSong(song90);
    };
    
private:
    SongIterator *song70s;
    SongIterator *song80s;
    SongIterator *song90s;
    void showInfoSong(const vector<SongInfo*> &song) const{
        for(const auto &s:song){
            cout << s->getSongName() << ' ' << s->getBandName() << ' ' << s->getYearReleased() << endl;
        }
    };
};

int main(int argc, const char * argv[]) {
    
    Songof70s *cur70=new Songof70s();
    
    cur70->addSong("Imag","byebye",1976);
    cur70->addSong("sdImag","afsbyebye",1976);
    cur70->addSong("Imagafsaf","byeafsfbye",1976);
    vector<SongInfo*>ans=cur70->getSongList();
    
    cout << ans.size() << endl;
    
    Songof80s *cur80=new Songof80s();
    
    cur80->addSong("Imadcag","byedbye",1985);
    cur80->addSong("sdImcdag","afcdsbyebye",1986);
    cur80->addSong("Imagacafsaf","eafsfbye",1986);
    
    Songof90s *cur90=new Songof90s();
    
    cur90->addSong("Imad123","bye123dbye",1992);
    cur90->addSong("sdIm3cdag","afcd32sbyebye",1993);
    cur90->addSong("Imaga4124cafsaf","eafs12414fbye",1990);
    
    
    diskDriver *mike=new diskDriver(cur70,cur80,cur90);
    mike->showList();
    
    return 0;
}
