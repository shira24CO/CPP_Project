//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Statue.h"
#include"Image.h"
#include"HangingStatue.h"


HangingStatue::HangingStatue(char* name_cr, int year_cr, char* current, float height, int length, float width, int amountScrews) :Image(name_cr, year_cr, current, height, length), Statue(name_cr, year_cr, current, height, area, width)
{
	this->amountScrews = amountScrews;
}

void HangingStatue::print() const
{
	Image::print();
	Statue::print();
	cout << "The amount of screws is: " << amountScrews;
}

HangingStatue::~HangingStatue()
{

}