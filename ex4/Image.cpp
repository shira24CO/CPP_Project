//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include"Creation.h"
#include"Image.h"

Image::Image(char* name_cr, int year_cr, char* current, float height, int length) :Creation(name_cr, year_cr, current, height)
{
	this->length = length;
}

void Image::print() const
{
	Creation::print();
	cout << "The length is: " << length;
}

Image::~Image()
{

}