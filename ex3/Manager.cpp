#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"
#include "Manager.h"
#include <iostream>
using namespace std;

Manager::Manager(char name[], long ID, int seniority) :Worker(name, ID,seniority)
{

}

Manager::~Manager()
{

}

long Manager::getSalary()const
{
	return (10000 + 800 * seniority);
}

void Manager::printName()const
{
	cout << name << endl;
}

void Manager::print() const
{
	Worker::print();
}