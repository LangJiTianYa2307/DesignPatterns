#pragma once
#include<iostream>
#include<string>
#include<map>

using namespace std;

//ֻ���ڶ���͹۵�ʱ��ʹ����Ԫģʽ��������
class Font {
private:
	string s;
public:
	Font(const string& s) {}
};

class FlyWeight
{
private:
	map<string, Font*> fontPool;
public:
	Font* getFont(const string& s)
	{
		map<string, Font*>::iterator item = fontPool.find(s);
		if (item != fontPool.end())
		{
			return fontPool[s];
		}
		else
		{
			Font* f = new Font(s);
			fontPool[s] = f;
			return f;
		}
	}

	void clear()
	{
		fontPool.clear();
	}
};

