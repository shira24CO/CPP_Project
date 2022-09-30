#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#pragma once
#include "Worker.h"

class Secretary :public Worker
{
private:

	int overTime;

public:
	Secretary(char[], long, int, int overTime);
	~Secretary();
	virtual long getSalary()const;
	const char* getType()const { return "teacher"; }
	void print() const;
};