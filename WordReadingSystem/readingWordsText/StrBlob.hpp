//
//  StrBlob.hpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#ifndef StrBlob_hpp
#define StrBlob_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

class StrBlobPtr;
class TextQuery;

class StrBlob{
    friend class TextQuery;
    friend class StrBlobPtr;
public:
    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
    StrBlob():data(std::make_shared<std::vector<std::string>>()){};
    StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){};
    const std::string front(const std::string &msg="The font value is ");
    const std::string back(const std::string &msg="The back value is ");
    void push_back(const std::string &s);
    void push_front(const std::string &s);
private:
    std::shared_ptr<std::vector<std::string>>data;
    void check(const int &idx, const std::string &msg="out of range!");
};

#endif /* StrBlob_hpp */
