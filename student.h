#define _CRT_SECURE_NO_WARNINGS
#define STUDENT_H
#include <iostream>



using namespace std;


class Student
{
private:
	char* name;
	char ID[10];
	int amountCourse;
	int* grades;
	static float sumGrades;
	static int amountOfCourses;

public:
	Student(char* name, char ID[10]);
	Student(const Student& s);
	~Student();
	char* getID() { return ID; }
	char* getName() { return name; }
	int getAmountCourse() { return amountCourse; }
	int* getGrades() { return grades; }
	friend ostream& operator<<(ostream& os, const Student& s);
	void operator+= (int grade);
	bool operator>(Student s);
	float average() const;
	static float averageOfAllStudent();
	friend class Worker;
	

};