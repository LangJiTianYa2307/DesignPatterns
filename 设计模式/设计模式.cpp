// 设计模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Singleton.h"
#include "ImpTemplateMethod.h"
#include "Stratege.h"
#include "Notifiers.h"
#include "Decorator.h"
#include "Factory.h"

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
#if 0
    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();
#endif 
#if 0
    TemplateMethod* temp = new ImpTemplateMethod();
    temp->Run();
#endif
#if 0
    DealSaleOrder* dso =new DealSaleOrder(new AddStratege());
    cout<<dso->operation(1,2)<<endl;
    dso = new DealSaleOrder(new SubStratege());
    cout << dso->operation(1, 2) << endl;
    delete dso;
#endif
#if 0
    Notifiers *notifiers= new Notifiers();
    notifiers->add(new HexObserver());
    notifiers->add(new BinOvserver());
    notifiers->notifyAllObservers();
#endif
#if 0 
    Stream* s1 = new FileStream();
    CrytoStream*s2 =new  CrytoStream(s1);
    BufferStream*s3 =  new BufferStream(s1);
    BufferStream* s4 = new BufferStream(s2);
    s4->Read(1);
    s4->Seed(1);
    s4->Write(' ');
#endif
#if 0
    ISplitterFactory* isf= new BinarySplitterFactory(); //可以实现运行时多态，通过装载工厂对象的不同，创建不同的对象。
    ISplitter* is =isf->CreateMethod();
    is->split();
#endif

}


