#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"
#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(char name[], long ID, int seniority, int amountOfSub, char** nameOfSub) :Worker(name, ID, seniority)
{
	this->amountOfSub = amountOfSub;
	this->nameOfSub = new char* [amountOfSub];
	if (!this->nameOfSub)
		return;
	for (int i = 0; i < amountOfSub; i++)
	{
		this->nameOfSub[i] = new char[strlen(nameOfSub[i]) + 1];
		if (!this->nameOfSub[i])
			return;
		strcpy(this->nameOfSub[i], nameOfSub[i]);
	}
}
Teacher::~Teacher()
{
	
	for (int i = 0; i < amountOfSub; i++)
	{
		delete[] this->nameOfSub[i];
	}
	delete[] this->nameOfSub;
}
long Teacher::getSalary()const
{
	return (5000 + (seniority * 500) + (300 * amountOfSub));
}
void Teacher::print() const
{
	Worker::print();
	cout << "teach on courses : ";
	for (int i = 0; i < amountOfSub; i++)
		cout << nameOfSub[i] << " , ";
	cout << endl;
}
const char* Teacher::checkCourse(char course[])const
{
	for (int i = 0; i < amountOfSub; i++)
		if (!strcmp(nameOfSub[i], course))
			return name;
	return "not found";
}
