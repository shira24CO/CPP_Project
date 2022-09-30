#define _CRT_SECURE_NO_WARNINGS
#include "Secretary.h"
#include "Worker.h"
#include <iostream>
using namespace std;

Secretary::Secretary(char name[], long ID, int seniority, int overTime) :Worker(name, ID, seniority)
{
	this->overTime = overTime;
}

Secretary::~Secretary()
{

}

long Secretary::getSalary()const
{
	return (5000 + 200 * seniority + 60 * overTime);
}

void Secretary::print() const
{
	Worker::print();
}