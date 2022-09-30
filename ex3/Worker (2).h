#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#pragma once

class Worker
{
protected:
	char* name;
	long ID;
	int seniority;

public:

	Worker(char[], long, int);
	virtual ~Worker();
	virtual long getSalary()const;
	virtual void print()const;
	virtual const char* getType()const { return "worker"; }
	long getID()const { return ID; }

};