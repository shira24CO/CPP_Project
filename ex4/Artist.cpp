//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include "Artist.h"
#include "LAB 2-DATE/Date.h"
#include "Creation.h"
#include <iostream>
using namespace std;



Artist::Artist(char* name, Date Dbirth, Date Ddeath)
{
	strcpy(this->name, name);
	this->Dbirth = Dbirth;
	this->Ddeath = Ddeath;
	creations = NULL;
	amount_creations = 0;
	
	
}

ostream& operator<<(ostream& os, const Artist& a)//
{
	os << "The artist's name: " << a.name << endl;
	os << "The birth date: ";
	a.Dbirth.printDate();
	os << endl << "The death date: ";
	a.Ddeath.printDate();
	os << "The artists creations:" << endl;
	for (int i = 0; i < a.amount_creations; i++)
	{
		os << "Creation number " << i + 1 << ":" << endl;
		a.creations[i]->print();
	}
	return os;
}

void Artist::AddCreation(Creation* c)
{
	Creation** updated_creations = NULL;
	updated_creations = new Creation* [amount_creations + 1];
	if (updated_creations)
		for (int i = 0; i < amount_creations; i++)
			updated_creations[i] = creations[i];
	updated_creations[amount_creations] = c;
	delete[] creations;
	creations = updated_creations;
}

Artist::~Artist()
{
	if (name != NULL)
		delete[] name;
	if (creations != NULL)
		delete[] creations;
}


char* Artist::get_name() const
{
	return name;
}

Creation** Artist::get_creations() const
{
	return creations;
}

int Artist::get_amount_creations() const
{
	return amount_creations;
}