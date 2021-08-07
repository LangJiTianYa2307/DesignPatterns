#pragma once
#include<iostream>
#include<list>

using namespace std;

class Observer {
public:
	virtual ~Observer() {}
	virtual void update() =0;
};

class HexObserver :public Observer {
public:
	void update()
	{
		cout << "hex update" << endl;
	}
};

class BinOvserver :public Observer {
public:
	void update()
	{
		cout << "Binary update" << endl;
	}
};

class Notifiers
{
private:
	list<Observer*> notices;
public:
	void add(Observer* obs)
	{
		notices.push_back(obs);
	}
	void remove(Observer* obs)
	{
		notices.remove(obs);
	}
	
	void notifyAllObservers()
	{
		list<Observer*>::iterator start = notices.begin();
		list<Observer*>::iterator end = notices.end();

		while (start != end)
		{
			(*start)->update();
			start++;
		}
	}
};

