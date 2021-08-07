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

//������
class FileStream :public Stream
{
public:
	virtual char Read(int number)
	{
		cout << "��ȡ�ļ���" << endl;
		char result=' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "�����ļ���λ��" << endl;
	}
	virtual void Write(char data)
	{
		cout << "д���ļ���" << endl;
    }
};

class NetworkStream :public Stream
{
public:
	virtual char Read(int number)
	{
		cout << "��ȡ������" << endl;
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "����������λ��" << endl;
	}
	virtual void Write(char data)
	{
		cout << "д��������" << endl;
	}
};

class MemoryStream :public Stream
{
public:
	virtual char Read(int number)
	{
		cout << "��ȡ�ڴ���" << endl;
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "�����ڴ���λ��" << endl;
	}
	virtual void Write(char data)
	{
		cout << "д���ڴ���" << endl;
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
		cout << "����" << endl;
		stream->Read(number);
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "����" << endl;
		stream->Seed(position);
	}
	virtual void Write(char data)
	{
		cout << "����" << endl;
		stream->Write(data);
	}
	CrytoStream(Stream* stream):Decorator(stream){}
};

class BufferStream :public Decorator
{
public:
	virtual char Read(int number)
	{
		cout << "����" << endl;
		stream->Read(number);
		char result = ' ';
		return result;
	}
	virtual void Seed(int position)
	{
		cout << "����" << endl;
		stream->Seed(position);
	}
	virtual void Write(char data)
	{
		cout << "����" << endl;
		stream->Write(data);
	}
	BufferStream(Stream* stream) :Decorator(stream) {}
};