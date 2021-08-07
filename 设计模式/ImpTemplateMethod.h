#pragma once
#ifndef __IMPTEMPLATEMEHOD_H
#define __IMPTEMPLATEMEHOD_H

#include "TemplateMethod.h"
#include<iostream>

using namespace std;

class ImpTemplateMethod :public TemplateMethod {
protected:
	bool step2()
	{
		cout << "step2" << endl;
		return false;
	}
	bool step4()
	{
		cout << "step4" << endl;
		return true;
	}
public:
	~ImpTemplateMethod();
};


#endif
