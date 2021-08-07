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
��������������չ�ķ��������ݴ���Ĳ��ԵĲ�ͬ��ִ�в�ͬ�Ĵ���
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

