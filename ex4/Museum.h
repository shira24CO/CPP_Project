//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<typeinfo>
#include "Artist.h"
#include "Creation.h"
#include"Image.h"
#include "Statue.h"

class Museum
{
private:
	Creation** creations_of_artists;
	Artist** artists;
	int size_creations;
	int size_artists;
public:
	friend class Artist;
	friend class Creation;
	Museum();
	void add_artist();
	void add_creation();
	void remove_creation(int index);
	void print_artists_one_creation() const;
	void print_creations() const;
	void print_images() const;
	void print_statues() const;
	void print_creations_specific_artist() const;
	void print_creations_specific_current() const;
	void print_artists_at_least_one_image() const;
	void print_artists_at_least_one_statue() const;
	void print_statues_above_specific_weight() const;
	void menu();
	virtual ~Museum();
};
