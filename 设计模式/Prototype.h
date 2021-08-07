#pragma once
#include<iostream>

using namespace std;

class ISplitter {
public:
	~ISplitter() {}
	virtual ISplitter* clone() =0 ;
	virtual void split() = 0;
};

class TxtSplitter :public ISplitter
{
public:
	ISplitter* clone()
	{
		return new TxtSplitter(*this);
	}
	void split()
	{
	}
};

class PictureSplitter :public ISplitter
{
public:
	ISplitter* clone()
	{
		return new PictureSplitter(*this);
	}
	void split()
	{
	}
};

class BinarrySplitter :public ISplitter
{
public:
	ISplitter* clone()
	{
		return new BinarrySplitter(*this);
	}
	void split()
	{
	}
};

class VideoSplitter :public ISplitter
{
public:
	ISplitter* clone()
	{
		return new VideoSplitter(*this);
	}
	void split()
	{
	}
};

//调用的复制构造函数

class Prototype
{
};

