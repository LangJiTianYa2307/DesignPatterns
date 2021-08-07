#pragma once
#include<iostream>

using namespace std;
class ISplitter {
public:
	virtual void split() = 0;
	~ISplitter() {}
};

class BinarySplitter :public ISplitter
{
public:
	void split()
	{
	}
};

class TxtSplitter :public ISplitter
{
public:
	void split()
	{
	}
};

class PictureSplitter :public ISplitter
{
public:
	void split()
	{
	}
};

class VideoSplitter :public ISplitter
{
public:
	void split()
	{
	}
};

class ISplitterFactory {
public:
	virtual ISplitter* CreateMethod() = 0;
	~ISplitterFactory(){}
};

class BinarySplitterFactory :public ISplitterFactory
{
public:
	ISplitter* CreateMethod()
	{
		return new BinarySplitter();
	}
};

class TxtSplitterFactory :public ISplitterFactory
{
public:
	ISplitter* CreateMethod()
	{
		return new TxtSplitter();
	}
};

class PictureSplitterFactory :public ISplitterFactory
{
public:
	ISplitter* CreateMethod()
	{
		return new PictureSplitter();
	}
};

class VideoSplitterFactory :public ISplitterFactory
{
public:
	ISplitter* CreateMethod()
	{
		return new VideoSplitter();
	}
};

class Factory
{

};

