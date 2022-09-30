#define _CRT_SECURE_NO_WARNINGS
#define WORKER_H
#include <iostream>
using namespace std;

class Worker
{
private:
	char* name;
	char ID[10];
	float salary;
	static float sumOfSalary;
	static int amountOfWorkers;
public:
	Worker(char* name, char ID[10], float salary);
	Worker(const Worker& w);
	~Worker();
	char* getID() { return ID; }
	char* getName() { return name; }
	float getSalary() { return salary; }
	friend ostream& operator<<(ostream& os, const Worker& w);
	void operator+=(float s);
	void operator*=(float s);
	bool operator>(Worker w);
	static float averageSalary();




};