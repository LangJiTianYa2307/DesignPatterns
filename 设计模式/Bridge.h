#pragma once
#include<iostream>
using namespace std;
class Image
{

};
class MessagerImp {
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() {}
};

class Messager {
protected:
    MessagerImp* messagerImp;
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;
    ~Messager() {}
    Messager(MessagerImp* mimp) :messagerImp(mimp) {}
};


//平台实现

class PCMessagerBase : public MessagerImp {
public:

    virtual void PlaySound() {
        //**********
    }
    virtual void DrawShape() {
        //**********
    }
    virtual void WriteText() {
        //**********
    }
    virtual void Connect() {
        //**********
    }
};

class MobileMessagerBase : public MessagerImp {
public:

    virtual void PlaySound() {
        //==========
    }
    virtual void DrawShape() {
        //==========
    }
    virtual void WriteText() {
        //==========
    }
    virtual void Connect() {
        //==========
    }
};



//业务抽象

class MessagerLite:public Messager {
public:

    virtual void Login(string username, string password) {

        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message) {

        this->messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image) {

        messagerImp->DrawShape();
        //........
    }
    MessagerLite(MessagerImp* mimp) :Messager(mimp) {}
};



class MessagerPerfect:public Messager {
public:

    virtual void Login(string username, string password) {

        messagerImp->PlaySound();
        //********
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message) {

        this->messagerImp->PlaySound();
        //********
        this->messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image) {

        messagerImp->PlaySound();
        //********
        messagerImp->DrawShape();
        //........
    }
    MessagerPerfect(MessagerImp* mimp) :Messager(mimp) {}
};

class Bridge
{
};

