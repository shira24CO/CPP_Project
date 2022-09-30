#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#pragma once
#include "Worker.h"

class Teacher :public Worker
{
protected:
	int amountOfSub;
	char** nameOfSub;

public:
	Teacher(char[], long, int , int amountOfSub, char** nameOfSub);
    ~Teacher();
	virtual long getSalary()const;
	const char* getType()const { return "teacher"; }
	const char* checkCourse(char course[])const;
	void print() const;
};


