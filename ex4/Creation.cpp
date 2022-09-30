//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Creation.h"
#include "Artist.h"


void Creation::set_current_of_creation(char* current)
{
	if (current)
	{
		current_creation = new char[strlen(current) + 1];
		if (current_creation)
			strcpy(current_creation, current);
		else
			exit(0);
	}
	current_creation = NULL;
}

void Creation::set_name_creation(char* name_cr)
{
	if (name_cr)
	{
		name_creation = new char[strlen(name_cr) + 1];
		if (name_creation)
			strcpy(name_creation, name_cr);
		else
			exit(0);
	}
	name_creation = NULL;
}
Creation::Creation(char* name_cr, int year_cr, char* current, float height)
{
	set_name_creation(name_cr);
	set_current_of_creation(current);
	year_creation = year_cr;
	height_creation = height;
}

Creation::~Creation()
{
	if (name_creation)
		delete[] name_creation;
	if (current_creation)
		delete[] current_creation;
	year_creation = 0;
	height_creation = 0;
	artist=NULL;
}

void Creation::print() const
{
	cout << "Name of creation:" << name_creation << endl << "Year that was created:" << year_creation << endl;
	cout << "Curreant:" << current_creation << endl << "Height:" << height_creation << endl ;
	cout << "Details of the artist:" << artist;
}


char* Creation::get_name_creation() const
{
	return name_creation;
}

int Creation::get_year_creation() const
{
	return year_creation;
}

char* Creation::get_current() const
{
	return current_creation;
}

float Creation::get_height() const
{
	return height_creation;
}

Artist* Creation::get_artist() const
{
	return artist;
}