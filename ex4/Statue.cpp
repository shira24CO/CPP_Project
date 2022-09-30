//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Creation.h"
#include"Statue.h"


Statue::Statue(char* name_cr, int year_cr, char* current, float height, float area, float weight) :Creation(name_cr, year_cr, current, height)
{
	this->area = area;
	this->weight = weight;
}


void Statue::print() const
{
	Creation::print();
	cout << "The area is: " << area;
	cout << "The width is: " << weight;
}

Statue::~Statue()
{

}

float Statue::get_weight() const
{
	return weight;
}