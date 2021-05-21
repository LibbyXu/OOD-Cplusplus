//
//  StrBlob.cpp
//  readingWordsText
//
//  Created by Lihua Xu on 5/18/21.
//

#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
};

StrBlobPtr StrBlob::end(){
    auto ret= StrBlobPtr(*this,data->size());
    return ret;
};

void StrBlob::check(const int &idx,  const std::string &msg){
    if(idx>=data->size()){
        throw std::out_of_range(msg);
    };
};

void StrBlob::push_back(const std::string &s){
    data->push_back(s);
};

void StrBlob::push_front(const std::string &s){
    data->insert(data->begin(),s);
};

const std::string StrBlob::front(const std::string &msg){
    check(0,msg);
    return data->front();
};

const std::string StrBlob::back(const std::string &msg){
    check(0,msg);
    return data->back();
};


StrBlobPtr StrBlob::begin() const{
    return StrBlobPtr(*this);
};

StrBlobPtr StrBlob::end() const{
    auto ret= StrBlobPtr(*this,data->size());
    return ret;
};
