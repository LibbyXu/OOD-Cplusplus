//
//  QueryResult.hpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#ifndef QueryResult_hpp
#define QueryResult_hpp
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <memory>
#include <string>
#include "QueryResult.hpp"
#include "StrBlob.hpp"

class QueryResult{
    friend std::ostream & print(std::ostream &os, const QueryResult&);
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::iterator line_it;
public:
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>>p, StrBlob &f);
    line_it begin() const;
    line_it end() const;
    StrBlob get_file();
private:
    std::string sought;
    StrBlob file;
    std::shared_ptr<std::set<line_no>>lines;
};



#endif /* QueryResult_hpp */
