#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>


using namespace std;

float Student::sumGrades=0.0;
int Student::amountOfCourses=0;

Student::Student(char* name, char ID[10])
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	strcpy(this->ID, ID);
	grades = NULL;
	amountCourse = 0;
}

Student::Student(const Student& s)
{
	
		name = new char[1 + strlen(s.name)];
		if (name == NULL)
		{
			amountCourse= 0;
			grades = NULL;
			return;
		}

		strcpy(name, s.name);
		strcpy(ID, s.ID);
		
		amountCourse = s.amountCourse;
		amountOfCourses += s.amountCourse;
		grades = new int[amountCourse];
		if (grades == NULL)
		{
			cout << "eror" << endl;
			return;
		}
		
		for (int i = 0; i < amountCourse; i++)
		{
			grades[i] = s.grades[i];
			sumGrades += s.grades[i];
		}


	}



Student::~Student()
{
	if (!(grades == NULL))
	{
		amountOfCourses -= amountCourse;
		for (int i = 0; i < amountCourse; i++)
		{
			sumGrades -= grades[i];
		}
	}
	if (name != NULL)
		delete[]name;
}

float Student::average() const
{
	float sum = 0.0;
	
	if (name == NULL)
	{
		cout << "eror"<<endl;
		return 0;
	}

	if (amountCourse== 0)
	{
		cout << "The student did not take any courses. The average is: 0"<<endl;
		return 0;
	}

	for (int i = 0; i < amountCourse; i++)
	{
		sum += grades[i];
	}

	return sum / amountCourse;
}


ostream& operator<<(ostream& os, const Student& s)
{
	os << "name:" << s.name << endl << "ID:" << s.ID << endl << "amount of Courses:" << s.amountCourse << endl ;
	cout << "The array of grades: { ";
	for (int i = 0; i < s.amountCourse; i++)
	{
		cout << s.grades[i]<<" ,";
	}
	cout << "}" << endl;
	cout << "average:" << s.average() << endl;
	
	return os;
}

void Student::operator+=(int grade)
{
	if (grade >= 0 && grade <= 100)
	{
		amountOfCourses++;
		
		sumGrades += grade;
		
		int *temp = new int[amountCourse + 1];
		for (int i = 0; i < amountCourse; i++)
		{
			temp[i] = grades[i];
		}
		
		temp[amountCourse] = grade;
		amountCourse++;
		delete[] grades;
		grades = temp;

	}

}

bool Student::operator>(Student s)
{
	if (this->average() > s.average())
		return true;
	return false;
}


float Student::averageOfAllStudent()
{
	if (amountOfCourses == 0)
		return 0;
	return (sumGrades / amountOfCourses);

}
