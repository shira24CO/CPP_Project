#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#pragma once
#include "Worker.h"

class Manager :public Worker
{
public:
	Manager(char[], long, int);
	~Manager();
	virtual long getSalary()const;
	const char* getType()const { return "manager"; }
	virtual void printName()const;
	void print() const;
};