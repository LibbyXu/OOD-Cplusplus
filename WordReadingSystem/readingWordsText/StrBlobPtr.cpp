//
//  StrBlobPtr.cpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#include "StrBlobPtr.hpp"
#include <iostream>
using namespace std;
// StrBlonPtr
StrBlobPtr::StrBlobPtr():curr(0){};

StrBlobPtr::StrBlobPtr(StrBlob &c, std::vector<std::string>::size_type sz):wpt(c.data),curr(sz){};

StrBlobPtr::StrBlobPtr(const StrBlob &c, std::vector<std::string>::size_type sz):wpt(c.data),curr(sz){};


std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t idx, const std::string &msg) const{
    auto cur=wpt.lock();
    if(!cur)
        throw std::runtime_error("unbound StrBlobPtr");
    if(cur->size()<=idx){
        throw std::out_of_range(msg);
    }
    return cur;
};

std::string & StrBlobPtr::deref(const std::vector<std::string>::size_type &num) const{
    auto cur=check(this->curr);
    return (*cur)[num];
};

StrBlobPtr& StrBlobPtr::incre(){
    check(this->curr);
    ++curr;
    return *this;
};
