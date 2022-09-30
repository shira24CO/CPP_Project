#define _CRT_SECURE_NO_WARNINGS
#include "Tutor.h"
#include "Teacher.h"
#include <iostream>
using namespace std;

Tutor::Tutor(char name[], long ID, int seniority, int amountOfSub, char** nameOfSub, char grade[3]): Teacher(name, ID, seniority, amountOfSub, nameOfSub)
{
	strcpy(this->grade, grade);
}

Tutor::~Tutor()
{

}

long Tutor::getSalary()const
{
	return (5000 + (seniority * 500) + (300 * amountOfSub) + 1000);
}

void Tutor::printName()const
{
	cout << "name:" << name << endl;
}

void Tutor::print() const
{
	Teacher::print();
	cout << "grade: " << grade << endl;
}