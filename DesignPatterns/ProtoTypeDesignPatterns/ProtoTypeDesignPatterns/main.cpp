//
//  main.cpp
//  ProtoTypeDesignPatterns
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <string>
using namespace std;

class Clone {
public:
    virtual Clone *clone() = 0;
    virtual void show() = 0;
};

//具体的实现类
class Sheep : public Clone {
public:
    Sheep(int id, std::string name)
            : Clone(), m_id(id), m_name(name) {
        std::cout << "Sheep() address:" << this << endl;
        cout << "Sheep() id address:" << &m_id << endl;
        cout << "Sheep() name address:" << &m_name << endl;
    }

    //关键代码拷贝构造函数
    Sheep(const Sheep &obj) {
        this->m_id = obj.m_id;
        this->m_name = obj.m_name;
        std::cout << "Sheep(const Sheep& obj) address:" << this << endl;
        cout << "Sheep(const Sheep& obj) id address:" << &m_id << endl;
        cout << "Sheep(const Sheep& obj) name address:" << &m_name << endl;
    }

    //关键代码克隆函数，返回return new Sheep(*this)
    Clone *clone(){
        return new Sheep(*this);//注意观察拷贝构造函数的实现,采用了深拷贝
    }

    void show(){
        cout << "id  :" << m_id << endl;
        cout << "name:" << m_name.data() << endl;
    }

private:
    int m_id;
    string m_name;
};

int main(int argc, const char * argv[]) {
    Clone *s1 = new Sheep(1, "abs");
    s1->show();

    return 0;
}
