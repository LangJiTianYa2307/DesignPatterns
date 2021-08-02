// 设计模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Singleton.h"

void ThreadFoo()
{
    this_thread::sleep_for(chrono::microseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    cout << singleton->value()<<"\n" << endl;;
}


void ThreadBar()
{
    this_thread::sleep_for(chrono::microseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    cout << singleton->value()<<"\n" << endl;
}


int main()
{
    //if you see same value,then singleton was reused
    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();
}

