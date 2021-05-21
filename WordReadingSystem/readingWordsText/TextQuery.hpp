//
//  TextQuery.hpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#ifndef TextQuery_hpp
#define TextQuery_hpp

#include <stdio.h>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "QueryResult.hpp"
#include "StrBlob.hpp"

class TextQuery{
    using line_no=std::vector<std::string>::size_type;
public:
    TextQuery(std::ifstream &inputText);
    QueryResult query(const std::string& searchWord);
private:
    StrBlob file;
    std::map<std::string,std::shared_ptr<std::set<line_no>>>wordToIdx;
};

#endif /* TextQuery_hpp */
