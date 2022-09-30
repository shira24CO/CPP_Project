#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "worker.h"
#include <iostream>

using namespace std;

void find(Student** s, Worker** w, int lengthS, int lengthW, char ID[9])
{
	for (int i = 0; i < lengthS; i++)
	{
		if (strcmp(s[i]->getID(), ID) == 0)
		{
			cout << "name:" << s[i]->getName() << endl << "amount of courses:" << s[i]->getAmountCourse() << endl;
			for (int j = 0; j < s[i]->getAmountCourse(); j++)
				cout << "grade " << i << s[i]->getGrades()[j] << endl;
		}

		else
			cout << "The student does not exist" << endl;
	}

	for (int i = 0; i < lengthW; i++)
	{
		if (strcmp(w[i]->getID(), ID) == 0)
		{
			cout << "name:" << w[i]->getName() << endl << "salary:" << w[i]->getSalary() << endl;
		}

		else
			cout << "The worker does not exist" << endl;
	}
}

int best(Student** s, int lengthS)
{
	float maxAverage = 0.0;
	int index = 0;
	for (int i = 0; i < lengthS; i++)
	{
		if (s[i]->average() > maxAverage)
		{
			maxAverage = s[i]->average();
			index = i;
		}
	}

	return index;
}

int rich(Worker** w, int lengthW)
{
	float maxSalary = 0.0;
	int index;
	for (int i = 0; i < lengthW; i++)
	{
		if (w[i]->getSalary() > maxSalary)
		{
			maxSalary = w[i]->getSalary();
			index = i;
		}
	}

	return index;
}

int main()
{
	Student** students = NULL;
	Worker** workers = NULL;
	int index;

	int lengthS;
	int lengthW;

	cout << "Enter the amount of students:" << endl;
	cin >> lengthS;

	cout << "Enter the amount of workers:" << endl;
	cin >> lengthW;

	char name[21];
	char ID[10];
	float salary = 0;
	int amountCourses;
	int *grades = NULL;
    

	students = new Student * [lengthS];
	workers = new Worker * [lengthW];
	for (int i = 0; i < lengthS; i++)
	{

		cout << "Enter the name of student " << i + 1 << endl;
		cin >> name;
		cout << "Enter the ID of the student " << i + 1 << endl;
		cin >> ID;
		students[i] = new Student(name, ID);
		
	}

	for (int i = 0; i < lengthW; i++)
	{
		cout << "Enter the name of worker " << i + 1 << endl;
		cin >> name;
		cout << "Enter the ID of the worker" << i + 1 << endl;
		cin >> ID;
		cout << "Enter the salary:" << endl;
		cin >> salary;
		workers[i] = new Worker(name, ID, salary);
	}

	int choise;
	do
	{
		cout << "Enter a number between 1-10:";
		cin >> choise;

		switch (choise)
		{
		case 1:
		{

			for (int i = 0; i < lengthS; i++)
			{
				cout << "The student " << i + 1 << ":" << endl << *(students[i]);
			}

			for (int i = 0; i < lengthW; i++)
			{
				cout << "The worker " << i + 1 << ":" << endl << *(workers[i]);

			}

			break;
		}
		case 2:

		{
			int grade;
			cout << "Enter index:" << endl;
			cin >> index;
			cout << "Enter grade:" << endl;
			cin >> grade;

			if(!(index >= 0 && index < lengthS))
			{
				cout << "The index is incorrect. " << endl;
			}
			else
			{
				students[index]->operator+=(grade);
				//*(students[index]) += grade;

			}
			break;
		}
		case 3:
		{
			int maxAverage = best(students, lengthS);
			cout << *(students[maxAverage]);
			break;
		}

		case 4:
		{
			cout << "The average of all students is:" << Student::averageOfAllStudent() << endl;
			break;
		}
		case 5:
		{
			cout << "Enter index:" << endl;
			cin >> index;
			if (!(index <= 0 && index < lengthW))
				cout << "The index is incorrect." << endl;
			else
			{

				float sum;
				cout << "Enter sum of money: " << endl;
				cin >> sum;

				workers[index]->operator+=(sum);
			}
			break;
		}

		case 6:
		{
			cout << "Enter index:" << endl;
			cin >> index;
			if (!(index <= 0 && index < lengthW))
				cout << "Eror. The index is incorrect" << endl;

			float precent;
			cout << "Enter a precent number:" << endl;
			cin >> precent;

			workers[index]->operator*=(precent);
			break;
		}
		case 7:
		{
			index = rich(workers, lengthW);
			cout << *(workers[index]);
			break;
		}
		case 8:
		{
			cout << "The average salary of all workers is:" << Worker::averageSalary() << endl;
			break;
		}
		case 9:
		{

			char ID[10];
			cout << "Enter ID:" << endl;
			cin >> ID;

			find(students, workers, lengthS, lengthW, ID);
			break;
		}

		case 10:
		{

			for (int i = 0; i < lengthS; i++)
			{
				delete students[i];
			}

			for (int i = 0; i < lengthW; i++)
			{
				delete workers[i];
			}

			delete[]students;
			delete[]workers;

			break;
		}

		default:
		{
			cout << "Eror";
			break;
		}

		}


	} while (choise!=10);

}



