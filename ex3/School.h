#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#pragma once
#include "Worker.h"
#include "Teacher.h"

class School
{
private:
	int numOfWorker;
	Worker** workers;
	bool isExist;

public:
	School();
	~School();
	void menu();
};

