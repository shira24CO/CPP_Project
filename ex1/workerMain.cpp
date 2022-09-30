#define _CRT_SECURE_NO_WARNINGS
#include "worker.h"
#include <iostream>
#include<iomanip>


using namespace std;

int main()
{
	Worker worker;//default constructor
	char name[15];
	long  id;
	double salary;
	int regularHours, extraHours;
	cout << "Enter name:";
	cin >> name;
	worker.setName(name);
	cout << "Enter ID:";
	cin >> id;
	worker.setID(id);
	cout << "Enter salary of per hour:";
	cin >> salary;
	worker.setSalaryPerHour(salary);
	cout << "Enter amount of regular hours:";
	cin >> regularHours;
	worker.setNumberOfRegularHours(regularHours);
	cout << "Enter amount of extra hours:";
	cin >> extraHours;
	worker.setNumberOfExtraHours(extraHours);
	cout << "salary is:" << fixed << setprecision(2)<<  worker.carculate()<<endl;
	cout << "Update amount of regular hours:";
	cin >> regularHours;
	worker.setNumberOfRegularHours(regularHours);
	worker.point();
	cout << "Update amount of extra hours:";
	cin >> extraHours;
	worker.setNumberOfExtraHours(extraHours);
	cout << "Update extra hours:" << worker.getNumberOfExtraHours() << endl;
	worker.point();
	cout << "Update salary per hour:";
	cin >> salary;
	worker.setSalaryPerHour(salary);
	worker.point();


	


}
