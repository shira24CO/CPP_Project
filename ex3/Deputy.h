#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#pragma once
#include "Tutor.h"

class Deputy :public Tutor
{
public:
	Deputy(char[], long, int, int amountOfSub, char** nameOfSub, char grade[3]);
	~Deputy();
	virtual long getSalary()const;
	virtual void printName()const;
	const char* getType()const { return "deputy"; }
	void print() const;

};