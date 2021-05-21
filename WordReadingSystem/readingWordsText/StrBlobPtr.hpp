//
//  StrBlobPtr.hpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#ifndef StrBlobPtr_hpp
#define StrBlobPtr_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <memory>
#include "StrBlob.hpp"

class StrBlobPtr{
    friend class TextQuery;
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob &c, std::vector<std::string>::size_type sz=0);
    StrBlobPtr(const StrBlob &c, std::vector<std::string>::size_type sz=0);
    std::string & deref(const std::vector<std::string>::size_type &num=0) const;
    StrBlobPtr& incre();
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
    std::shared_ptr<std::vector<std::string>> check(size_t idx, const std::string &msg="Out of range!")const;
    std::weak_ptr<std::vector<std::string>>wpt;
    std::vector<std::string>::size_type curr;
};
#endif /* StrBlobPtr_hpp */
