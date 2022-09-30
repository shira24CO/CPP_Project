//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Creation.h"
using namespace std;

class Statue :public Creation
{
protected:
	float area;
	float weight;

public:
	friend class Museum;
	Statue(char* name_cr, int year_cr, char* current, float height, float area, float weight);
	void print() const;
	~Statue();
	float get_weight() const;
};
