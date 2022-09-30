#define _CRT_SECURE_NO_WARNINGS
#include "worker.h"
#include <iostream>
#include<iomanip>

using namespace std;

Worker::Worker()// בנאי מאתחל
{
    *name = NULL;
    ID = 0;
    salaryPerHour = 0;
    numberOfRegularHours = 0;
    numberOfExtraHours = 0;
}

void Worker::setName(char* name)
{
    strcpy(this->name, name);
}

void Worker::setID(long ID)
{
    this->ID = ID;
}

void Worker::setSalaryPerHour(double salary)
{
    this->salaryPerHour = salary;
}

void Worker::setNumberOfRegularHours(int regularHours)
{
    this->numberOfRegularHours = regularHours;
}

void Worker::setNumberOfExtraHours(int extraHours)
{
    this->numberOfExtraHours = extraHours;
}

double Worker::carculate()
{
    return (numberOfRegularHours * salaryPerHour + numberOfExtraHours * 1.5 * salaryPerHour);
}

void Worker::point()
{
    cout << getName() << "," << getID() << "," <<fixed << setprecision(2) << getSalaryPerHour() << "," << getNumberOfRegularHours() << "," << getNumberOfExtraHours()<<","<< fixed << setprecision(2) << carculate() << endl;
}