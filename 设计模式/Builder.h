#pragma once
#include <iostream>
using namespace std;

class House
{

};

class StoneHouse:public House {

};

class HouseBuilder {
public:
	House* GetResult()
	{
		return pHouse;
	}
public:
	House* pHouse;
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual bool BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};

class StoneHouseBuilder :public HouseBuilder {
public:
    StoneHouseBuilder(House* pHouse)
    {
        this->pHouse = pHouse;
    }
protected:

    virtual void BuildPart1() {
        //pHouse->Part1 = ...;
    }
    virtual void BuildPart2() {

    }
    virtual bool BuildPart3() {

    }
    virtual void BuildPart4() {

    }
    virtual void BuildPart5() {

    }
};

class HouseDirector
{
private:
    HouseBuilder* pHouseBuilder;
public:
    HouseDirector(HouseBuilder* pHouseBuilder)
    {
        this->pHouseBuilder = pHouseBuilder;
    }
    House* Construct() 
    {
        pHouseBuilder->BuildPart1();

        for (int i = 0; i < 4; i++) {
            pHouseBuilder->BuildPart2();
        }

        bool flag = pHouseBuilder->BuildPart3();

        if (flag) {
            pHouseBuilder->BuildPart4();
        }

        pHouseBuilder->BuildPart5();

        return pHouseBuilder->GetResult();
    }
};

class Builder
{
};

