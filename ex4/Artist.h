//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
#include "LAB 2-DATE/Date.h"
#include"Creation.h"
class Creation;

class Artist
{
protected:
	char* name;
	Date Dbirth;
	Date Ddeath;
	Creation** creations;
	int amount_creations;
	

public:
	friend class Creation;
	friend class Museum;
	Artist(char* name, Date Dbirth, Date Ddeath);
	void AddCreation(Creation* c);
	friend ostream& operator<<(ostream& os, const Artist& a);
	~Artist();
	char* get_name() const;
	Creation** get_creations() const;
	int get_amount_creations() const;
};
