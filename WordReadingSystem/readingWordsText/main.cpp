//
//  main.cpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
// count the words in the line

#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <memory>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"
using namespace std;

ostream & print(ostream & out, const QueryResult &qr){
    out << qr.sought << " appers " << qr.lines->size() << " times:\n";
    
    StrBlobPtr start(qr.file.begin());
    
    for(const auto &s:(*qr.lines)){
        out << "   (LineNo." << s+1 << ")  " << start.deref(s) << endl;
    };
    
    return out;
};

int main(int argc, const char * argv[]) {
    
    ifstream inPut("data.txt");
    
    if(!inPut){
        cerr << "The file cannot be opened, please check!" << endl;
        return -1;
    };
    
    TextQuery curArticel(inPut);
    
    
    while(true){
        cout << "Please enter the word need to be checked: (q to quit)\n";
        string str;
        if(!(cin >> str) || str=="q")break;
        cout << endl;
        print(cout,curArticel.query(str));
        cout << endl;
    };
    cout << "The program ended!" << endl;
    
    return 0;
}
