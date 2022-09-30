//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Image.h"
#include"Statue.h"
using namespace std;

class HangingStatue :virtual public Image, virtual public Statue
{
private:
	int amountScrews;


public:
	friend class Museum;
	HangingStatue(char* name_cr, int year_cr, char* current, float height, int length, float width, int amountScrews);
	void print() const;
	~HangingStatue();
};
