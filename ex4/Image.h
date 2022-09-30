//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Creation.h"

class Image :public Creation
{
protected:
	int length;

public:
	Image(char* name_cr, int year_cr, char* current, float height, int length);
	void print() const;
	~Image();
};