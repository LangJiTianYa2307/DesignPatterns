#pragma once
#include <iostream>

class Stratege
{
public:
	virtual ~Stratege()
	{

	}
	virtual int calculation(int num1,int num2) = 0;
};


class AddStratege :public Stratege
{
public:
	int calculation(int num1,int num2)
	{
		return num1 + num2;
	}
};

class SubStratege :public Stratege
{
public:
	int calculation(int num1, int num2)
	{
		return num1 - num2;
	}
};
/*
在这里可以添加扩展的方法，根据传入的策略的不同，执行不同的代码
*/

class DealSaleOrder {
private:
	Stratege* stratege;
public:
	DealSaleOrder(Stratege* s)
	{
		stratege = s;
	}
	int operation(int num1, int num2)
	{
		return stratege->calculation(num1,num2);
	}
	~DealSaleOrder()
	{
		delete stratege;
	}
};

