#define _CRT_SECURE_NO_WARNINGS
#include "Temp.h"
#include "Teacher.h"
#include <iostream>
using namespace std;

Temp::Temp(char name[], long ID, int seniority, int amountOfSub, char** nameOfSub, int weeklyHours): Teacher(name, ID, seniority, amountOfSub, nameOfSub)
{
	this->weeklyHours= weeklyHours;
}

Temp::~Temp()
{

}

long Temp::getSalary()const
{
	if (seniority > 5 && weeklyHours > 10)
		return (700 + 300 * weeklyHours);
	return (300 * weeklyHours);
}

void Temp::print() const
{
	Teacher::print();
	cout << "weeklyHours : " << weeklyHours << endl;
}

