#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#pragma once
#include "Teacher.h"

class Temp :public Teacher
{
private:
	int weeklyHours;

public:

	Temp(char[], long, int, int amountOfSub, char** nameOfSub, int weeklyHours);
	~Temp();
	virtual long getSalary()const;
	const char* getType()const { return "temp"; }
	void print() const;
};