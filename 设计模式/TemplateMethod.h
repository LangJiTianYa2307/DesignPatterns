#pragma once
#ifndef __TEMPLATEMETHOD_H
#define __TEMPLATEMETHOD_H
#include <iostream>

using namespace std;

class TemplateMethod
{
protected:
	void step1();
	void step3();
	void step5();
	virtual bool step2() = 0;
	virtual bool step4() = 0;
public:
	void Run()
	{
		step1();
		if (step2())
			step3();
		if (step4())
			step5();
	}
	virtual ~TemplateMethod() {}
};

#endif
