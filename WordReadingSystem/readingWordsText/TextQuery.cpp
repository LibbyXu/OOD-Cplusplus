//
//  TextQuery.cpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <iostream>
#include <memory>
#include "TextQuery.hpp"

using namespace std;

//constructor
TextQuery::TextQuery(ifstream &inputText){
    //iterative put the inputText string into the program
    string text;
    while(getline(inputText,text)){
        file.data->push_back(text);
        vector<string>::size_type curLine=file.data->size()-1;
        stringstream words(text);
        string word;
        while(words>>word){
            auto &line=wordToIdx[word];
            if(!line)line=make_shared<set<line_no>>();
            line->insert(curLine);            
        };
    };
};

//method
QueryResult TextQuery::query(const string& searchWord){
    auto it=wordToIdx.find(searchWord);
    
    shared_ptr<set<line_no>>nodata=make_shared<set<line_no>>();
    
    if(it==wordToIdx.end()){
        return QueryResult(searchWord, nodata, file);
    }
    return QueryResult(searchWord, it->second, file);
};
