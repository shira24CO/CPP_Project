#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#pragma once
#include "Teacher.h"

class Tutor :public Teacher
{
protected:

	char grade[4];//הכיתה שאותה מחנך

public:
	Tutor(char[], long, int, int amountOfSub, char** nameOfSub, char grade[3]);
	~Tutor();
	virtual long getSalary()const;
	virtual void printName()const;
	char* getGrade() { return grade; }
	virtual char** getNameOfSub() { return nameOfSub; }
	virtual int getAmountOfSub() { return amountOfSub; }
	const char* getType()const { return "tutor"; }
	void print() const; 
};