#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"
#include <iostream>

float Worker::sumOfSalary = 0.0;
int Worker:: amountOfWorkers = 0;

using namespace std;

Worker::Worker(char* name, char ID[10], float salary)
{
	if (name == NULL || ID==NULL)
	{
		this->salary = 0;
		return;
	}

	else
	{
		this->name = new char[strlen(name) + 1];
	    strcpy(this->name, name);
		strcpy(this->ID, ID);
		this->salary = salary;
		amountOfWorkers++;
		sumOfSalary += salary;
		
	}

}

Worker::Worker(const Worker& w)
{
	if (w.name == NULL || w.ID == NULL)
	{
		this->salary = 0;
		return;
	}

	else
	{
		amountOfWorkers++;
		this->name = new char[strlen(w.name) + 1];
		strcpy(this->name, w.name);
		strcpy(this->ID, ID);
		this->salary = w.salary;
		sumOfSalary += w.salary;
	}
}

	Worker::~Worker()
	{
		if (name != NULL)
			delete[]name;
		
	}

	ostream& operator<<(ostream& os, const Worker& w)
	{
		os << "name:" << w.name << endl << "ID:" << w.ID << endl << "salary:" << w.salary << endl;

		return os;
	}

	void Worker::operator+=(float s)
	{
		this->salary += s;
		sumOfSalary += s;
	}

	void Worker::operator*=(float s)
	{
		this->salary = this->salary+ (this->salary * (s / 100));
		sumOfSalary += (this->salary * (s / 100));
	}

	bool Worker::operator>(Worker w)
	{
		if (this->salary > w.salary)
			return true;
		return false;
	}

	float Worker::averageSalary()
	{
		if (amountOfWorkers == 0)
			return 0;;
		return (sumOfSalary / amountOfWorkers);
	}