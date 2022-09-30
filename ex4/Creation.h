//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Artist.h"
class Artist;

class Creation
{
protected:
	char* name_creation;
	int year_creation;
	char* current_creation;
	float height_creation;
	Artist* artist;

public:
	friend class Artist;
	friend class Museum;
	Creation(char* name_cr, int year_cr, char* current, float height);
	virtual ~Creation();
	void set_name_creation(char* name_creation);
	void set_current_of_creation(char* current_of_creation);
	virtual void print() const;
	char* get_name_creation() const;
	int get_year_creation() const;
	char* get_current() const;
	float get_height() const;
	Artist* get_artist() const;
};
