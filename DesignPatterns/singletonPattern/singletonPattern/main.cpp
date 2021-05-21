//
//  main.cpp
//  singletonPattern
//
//  Created by Lihua Xu on 5/11/21.
//

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
 
std::mutex mtx;


class Singleton
{
public:
    static Singleton* get_instance()
    {
        if (p_instance == NULL)//第一次调用要判断指针是否为空
        {
            mtx.lock();//thread safety
            if (p_instance == NULL)
            {
                p_instance = new Singleton();
                cout << "唯一创建(访问)实例的方法" << endl;
            }
            mtx.unlock();
        }
 
        return p_instance;
    }
 
private:
    Singleton(){}; //构造函数设计成私有的
    static Singleton *p_instance;  //用类的指针指向唯一的实例
};
Singleton* Singleton::p_instance=NULL;

int main(int argc, char*argv[])
{
    Singleton *object = Singleton::get_instance();
 
    return 0;
}
