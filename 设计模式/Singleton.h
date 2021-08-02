#pragma once
#ifndef __SINGLETON_H
#define __SINGLETON_H

#include<iostream>
#include<string>
#include<mutex>

using namespace std;

class Singleton
{
private:
	static Singleton* singleton;
	static mutex mutex_;
protected:
	Singleton(const string value) :value_(value)
	{
	}
	~Singleton() {}
	string value_;
public:
	/*Singleton should not be cloneable
	*/
    
	Singleton(Singleton& other) = delete;
	/*Singleton should not be assignable*/
	void operator=(const Singleton&) = delete;

	/*
	* This is the static method that controls the access to the singleton instance.
	*/
	static Singleton* GetInstance(const string& value);

	/*Finally,any singleton should define some business logic,which we can executed on its instance.*/
	void SomeBusinessLogic()
	{
	}
	
	string value() const
	{
		return value_;
	}
};

#endif
