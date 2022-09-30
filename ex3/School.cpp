#define _CRT_SECURE_NO_WARNINGS
#define SIZE 20
#include "Worker.h"
#include "Teacher.h"
#include "Temp.h"
#include "Tutor.h"
#include "Deputy.h"
#include "Manager.h"
#include "School.h"
#include "Secretary.h"
#include <iostream>
#include <typeinfo>
using namespace std;

School::School()
{
	numOfWorker = 0;
	workers = NULL;
	isExist = false;
}
School::~School()
{}
void School::menu()
{
	int choice, numOfCourses;
	bool flag;
	char type;
	char** nameOfCourses;
	char name[10], str[SIZE];
	long id;
	Worker** temp = NULL;
	int seniority;
	do
	{
		cout << "------------menu------------" << endl;
		cout << "please enter your choose :" << endl;
		cout << "1) Add worker " << endl << "2) Print workers " << endl << "3) Print profession " << endl
			<< "4) Print tutors " << endl << "5) Print management " << endl << "6) Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			flag = false;
			temp = new Worker * [numOfWorker + 1];
			for (int i = 0; i < numOfWorker; i++)
			{
				//workers[i]->print();
				temp[i] = workers[i];
			}

			cout << "enter name, id and seniority " << endl;
			cin >> name >> id >> seniority;
			for (int i = 0; i < numOfWorker; i++)
				if (workers[i]->getID() == id)
				{
					cout << "this id is already enter " << endl;
					flag = true;
					break;
				}
			
			if (flag)
				break;
			
			cout << "Choose your type of worker : " << endl << "a - Teacher " << endl << "b - Temp " << endl
				<< "c - Tutor " << endl << "d - Deputy " << endl << "e - Manager " << endl << "f - Secretary " << endl;
			cin >> type;
			switch (type)
			{
			case 'a':
			{
				cout << "enter number of courses: " << endl;
				cin >> numOfCourses;
				nameOfCourses = new char* [numOfCourses];
				cout << "enter courses : " << endl;
				for (int i = 0; i < numOfCourses; i++)
				{
					cin >> str;
					nameOfCourses[i] = new char[strlen(str) + 1];
					strcpy(nameOfCourses[i], str);

				}
				Teacher* tempteacher = new Teacher(name, id, seniority, numOfCourses, nameOfCourses);
				if (!tempteacher)
					break;
				for (int i = 0; i < numOfWorker; i++)
					temp[i] = workers[i];
				temp[numOfWorker] = tempteacher;
				numOfWorker++;
				delete workers;
				workers = temp;
			}
			break;
			case 'b':
			{
				int weeklyhour;
				cout << "enter number of courses: " << endl;
				cin >> numOfCourses;
				nameOfCourses = new char* [numOfCourses];
				cout << "enter courses : " << endl;
				for (int i = 0; i < numOfCourses; i++)
				{
					cin >> str;
					nameOfCourses[i] = new char[strlen(str) + 1];
					strcpy(nameOfCourses[i], str);
				}
				cout << "enter weekly hour : " << endl;
				cin >> weeklyhour;
				Temp* temptemp = new Temp(name, id, seniority, numOfCourses, nameOfCourses, weeklyhour);
				if (!temptemp)
					break;
				for (int i = 0; i < numOfWorker; i++)
					temp[i] = workers[i];
				temp[numOfWorker] = temptemp;
				numOfWorker++;
				delete workers;
				workers = temp;
			}
			break;
			case 'c':
			{
				char grade[3];
				cout << "enter number of courses: " << endl;
				cin >> numOfCourses;
				nameOfCourses = new char* [numOfCourses];
				cout << "enter courses : " << endl;
				for (int i = 0; i < numOfCourses; i++)
				{
					cin >> str;
					nameOfCourses[i] = new char[strlen(str) + 1];
					strcpy(nameOfCourses[i], str);
				}
				cout << "enter grade : " << endl;
				cin >> grade;
				for (int i = 0; i < numOfWorker; i++)
				{
					Tutor* t = dynamic_cast<Tutor*>(workers[i]);
					if (t == NULL)
						continue;
					if (strcmp(grade, dynamic_cast<Tutor*>(workers[i])->getGrade()) == 0)
						
					{
						cout << "there is already tutor in this grade " << endl;
						flag = true;
						break;
					}
				}
				if (flag)
					break;
				Tutor* temptutor = new Tutor(name, id, seniority, numOfCourses, nameOfCourses, grade);
				if (!temptutor)
					break;
				for (int i = 0; i < numOfWorker; i++)
					temp[i] = workers[i];
				temp[numOfWorker] = temptutor;
				numOfWorker++;
				delete workers;
				workers = temp;
			}
			break;
			case 'd':
			{
				char grade[3];
				cout << "enter number of courses: " << endl;
				cin >> numOfCourses;
				nameOfCourses = new char* [numOfCourses];
				cout << "enter courses : " << endl;
				for (int i = 0; i < numOfCourses; i++)
				{
					cin >> str;
					nameOfCourses[i] = new char[strlen(str) + 1];
					strcpy(nameOfCourses[i], str);
				}
				cout << "enter grade : " << endl;
				cin >> grade;
				for (int i = 0; i < numOfWorker; i++)
				{
					Tutor* t = dynamic_cast<Tutor*>(workers[i]);
					if (t == NULL)
						continue;
					if (strcmp(grade, dynamic_cast<Tutor*>(workers[i])->getGrade()) == 0)
						
					{
						cout << "there is already tutor in this grade " << endl;
						flag = true;
						break;
					}
				}
				if (flag)
					break;
				Deputy* tempdeputy = new Deputy(name, id, seniority, numOfCourses, nameOfCourses, grade);
				if (!tempdeputy)
					break;
				for (int i = 0; i < numOfWorker; i++)
					temp[i] = workers[i];
				temp[numOfWorker] = tempdeputy;
				numOfWorker++;
				delete workers;
				workers = temp;
			}
			break;
			case 'e':
			{
				if (isExist)
				{
					cout << "there is maneger alraedy!" << endl;
					break;
				}
				Manager* tempmanger = new Manager(name, id, seniority);
				if (!tempmanger)
					break;
				for (int i = 0; i < numOfWorker; i++)
					temp[i] = workers[i];
				temp[numOfWorker] = tempmanger;
				numOfWorker++;
				delete workers;
				workers = temp;
				isExist = true;
			}
			break;
			case 'f':
			{
				int extrahour;
				cout << "enter extra hour : " << endl;
				cin >> extrahour;
				Secretary* temsecr = new Secretary(name, id, seniority, extrahour);
				if (!temsecr)
					break;
				for (int i = 0; i < numOfWorker; i++)
					temp[i] = workers[i];
				temp[numOfWorker] = temsecr;
				numOfWorker++;
				delete workers;
				workers = temp;
			}
			break;
			}
		}
		break;
		case 2:
		{
			if (numOfWorker == 0)
			{
				cout << "no workers! " << endl;
				break;
			}
			for (int i = 0; i < numOfWorker; i++)
			{
				cout << workers[i]->getType() << " : ";
				workers[i]->print();
				cout << "salary : " << workers[i]->getSalary() << endl;
			}
		}
		break;
		case 3:
		{
			char tmpcourse[SIZE];
			if (numOfWorker == 0)
			{
				cout << "no workers! " << endl;
				break;
			}
			cout << "enter name of course : " << endl;
			cin >> tmpcourse;
			for (int i = 0; i < numOfWorker; i++)
			{
				Teacher* t = dynamic_cast<Teacher*>(workers[i]);
				if (t == NULL)
					continue;
				if (t->checkCourse(tmpcourse) != "not found")
					cout << t->checkCourse(tmpcourse) << endl;
				
			}
		}
		break;
		case 4:
		{
			if (numOfWorker == 0)
			{
				cout << "no workers! " << endl;
				break;
			}
			for (int i = 0; i < numOfWorker; i++)
			{
				Tutor* t = dynamic_cast<Tutor*>(workers[i]);
				if (t == NULL)
					continue;
				t->printName();
				cout << endl << t->getGrade()<<endl;

			}
		}
		break;
		case 5:
		{
			if (numOfWorker == 0)
			{
				cout << "no workers! " << endl;
				break;
			}
			for (int i = 0; i < numOfWorker; i++)
			{
				if (!(strcmp(typeid(*workers[i]).name(), "class Manager")))
				{
					Manager* m = dynamic_cast<Manager*>(workers[i]);
					cout << "manager :" ;
					m->printName();
					continue;
				}
				else if (!(strcmp(typeid(*workers[i]).name(), "class Deputy")))
				{
					Deputy* d = dynamic_cast<Deputy*>(workers[i]);
					cout << "deputy :" ;
					d->printName();
				}

			}
		}
		break;
		case 6:
			break;
			
		}
	} while (choice != 6);
}
