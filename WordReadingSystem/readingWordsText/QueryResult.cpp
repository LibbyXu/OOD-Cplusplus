//
//  QueryResult.cpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#include "QueryResult.hpp"
#include <string>
#include <vector>
#include <set>
#include <memory>
using namespace std;

//constructor
QueryResult::QueryResult(const string &s, shared_ptr<set<line_no>>p, StrBlob &f):file(f),lines(p),sought(s){};

QueryResult::line_it QueryResult::begin() const{
    return lines->begin();
};

QueryResult::line_it QueryResult::end() const{
    return lines->end();
};

StrBlob QueryResult::get_file(){
    return file;
};
