#pragma once
#include<iostream>

using namespace std;

class Stream {
public:
	virtual char Read(int number) = 0;
	virtual void Seed(int position) = 0;
	virtual void Write(char data) = 0;
	~Stream() {};
};

//主体类
class FileStream :public Stream
{
public:
	virtual char Read(int number)
	{
		cout << "读取文件流" << endl;
		char result=' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "设置文件流位置" << endl;
	}
	virtual void Write(char data)
	{
		cout << "写入文件流" << endl;
    }
};

class NetworkStream :public Stream
{
public:
	virtual char Read(int number)
	{
		cout << "读取网络流" << endl;
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "设置网络流位置" << endl;
	}
	virtual void Write(char data)
	{
		cout << "写入网络流" << endl;
	}
};

class MemoryStream :public Stream
{
public:
	virtual char Read(int number)
	{
		cout << "读取内存流" << endl;
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "设置内存流位置" << endl;
	}
	virtual void Write(char data)
	{
		cout << "写入内存流" << endl;
	}
};

class Decorator:public Stream
{
protected:
	Stream* stream;
	Decorator(Stream* stream)
	{
		this->stream = stream;
	}
public:
	~Decorator() {}
};

class CrytoStream :public Decorator
{
public:
	virtual char Read(int number)
	{
		cout << "加密" << endl;
		stream->Read(number);
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "加密" << endl;
		stream->Seed(position);
	}
	virtual void Write(char data)
	{
		cout << "加密" << endl;
		stream->Write(data);
	}
	CrytoStream(Stream* stream):Decorator(stream){}
};

class BufferStream :public Decorator
{
public:
	virtual char Read(int number)
	{
		cout << "缓存" << endl;
		stream->Read(number);
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "缓存" << endl;
		stream->Seed(position);
	}
	virtual void Write(char data)
	{
		cout << "缓存" << endl;
		stream->Write(data);
	}
	BufferStream(Stream* stream) :Decorator(stream) {}
};