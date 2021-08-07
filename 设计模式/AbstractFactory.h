#pragma once
#include<iostream>
#include<string>

using namespace std;

class IDBConnection {
public:
	virtual void CreateString(string s) = 0;
	~IDBConnection() {}
};

class IDataReadr {
public:
	virtual void Read() = 0;
	~IDataReadr() {}

};

class IDBCommand {
public:
	virtual void ConmandText(string s) = 0;
	virtual void SetConnection() = 0;
	virtual void ExecuteReader() = 0;
	~IDBCommand() {}
};

//Ö§³ÖSQL Server
class SqlConnection : public IDBConnection {
public:
	void CreateString(string s)
	{
	}
};
class SqlCommand : public IDBCommand {
public:
	virtual void ConmandText(string s)
	{
	}
	virtual void SetConnection()
	{
	}
	virtual void ExecuteReader()
	{

	}
};
class SqlDataReader : public IDataReadr{
public:
	virtual void Read()
	{

	}
};


class AbstractFactory
{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
	virtual IDataReadr* CreateDataReader() = 0;
};


class SqlDBFactory:public AbstractFactory {
public:
	virtual IDBConnection* CreateDBConnection()
	{
	}
	virtual IDBCommand* CreateDBCommand()
	{
	}
	virtual IDataReadr* CreateDataReader()
	{
	}
};