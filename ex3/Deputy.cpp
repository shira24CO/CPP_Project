#define _CRT_SECURE_NO_WARNINGS
#include "Deputy.h"
#include "Tutor.h"
#include <iostream>
using namespace std;

Deputy::Deputy(char name[], long ID, int seniority, int amountOfSub, char** nameOfSub, char grade[3]):Tutor(name, ID, seniority, amountOfSub, nameOfSub, grade)
{

}

Deputy::~Deputy()
{

}

long Deputy::getSalary()const
{
	return (5000 + (seniority * 500) + (300 * amountOfSub) + 1000 + 2500);
}

void Deputy::printName()const
{
	cout << name << endl;
}

void Deputy::print() const
{
	Tutor::print();
	
}