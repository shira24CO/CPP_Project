#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker(char name[], long ID, int seniority)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->ID = ID;
	this->seniority = seniority;
}

Worker::~Worker()
{
	if (name != NULL)
		delete[]name;
}

long Worker::getSalary()const
{
	return 0;
}

void Worker::print() const
{
	cout << "Name: " << name << endl;
	cout << "ID: " << ID << endl;
	cout << "Seniority: " << seniority << endl;
	cout << "Salary: " << getSalary() << endl;
}


