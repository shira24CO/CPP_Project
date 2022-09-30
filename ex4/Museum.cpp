//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<typeinfo>
#include "Artist.h"
#include "Creation.h"
#include"Image.h"
#include "Statue.h"
#include "Museum.h"
#include "HangingStatue.h"
#include "LAB 2-DATE/Date.h"

Museum::Museum()
{
	creations_of_artists = NULL;
	artists = NULL;
	size_creations = 0;
	size_artists = 0;
}

void Museum::add_artist()
{
	char name_a[30];
	Date birth, death;
	cout << "Enter the name of the artist:" << endl;
	cin >> name_a;
	cout << "Enter date of birth";
	cin >> birth;
	cout << "Enter date of death(if alive type 0.0.0)" << endl;
	cin >> death;
	Artist a(name_a, birth, death);
	size_artists++;
	Artist** temp = new Artist* [size_artists];
	if (temp == NULL)
	{
		cout << "eror" << endl;
		exit(1);
	}
	for (int i = 0; i < size_artists-1; i++)
	{
		temp[i] = artists[i];
	}
	temp[size_artists - 1] = &a;
	delete[] artists;
	artists = temp;
}

void Museum::add_creation()
{
	char nameCr[30], nameCurrent[30], nameA[30];
	int year;
	float height;
	bool flag = false;
	Date birth, death;
	cout << "Enter the name of the creation:" << endl;
	cin >> nameCr;
	cout << "Enter year of creation:" << endl;
	cin >> year;
	cout << "Enter Current:" << endl;
	cin >> nameCurrent;
	cout << "Enter height of the creation:" << endl;
	cin >> height;
	cout << "Enter the name of the artist who owns this creation:" << endl;
	cin >> nameA;
	for (int i = 0; i < size_artists; i++)
	{
		if (strcmp(artists[i]->get_name(), nameA) == 0)
		{
			Creation cr(nameCr, year, nameCurrent, height);
			size_creations++;
			flag = true;
			artists[i]->AddCreation(&cr);
			Creation** temp = new Creation * [size_creations];
			if (temp == NULL)
			{
				cout << "eror" << endl;
				exit(1);
			}
			for (int i = 0; i < size_creations; i++)
			{
				temp[i] = creations_of_artists[i];
			}

			temp[size_creations - 1] = &cr;
			delete[] creations_of_artists;
			creations_of_artists = temp;
		}
		
	}
	if (flag == false)
	{
		cout << "Artist with this name does not exist" << endl;
		cout << "adding the artist:" << endl;
		add_artist();
	}
	
}

void Museum::remove_creation(int index)
{
	Creation** temp = new Creation * [size_creations - 1];
	if (temp == NULL)
	{
		cout << "eror" << endl;
	}

	for (int i = 0; i < index; i++)
	{
		temp[i] = creations_of_artists[i];
	}

	for (int i = index + 1; i < size_creations - 1; i++)
	{
		temp[i] = creations_of_artists[i];
	}

	delete[] creations_of_artists;
	creations_of_artists = temp;

}

void Museum::print_artists_one_creation() const
{
	for (int i = 0; i < size_artists; i++)
	{
		if (artists[i]->get_amount_creations() >= 1)
			cout << *artists[i];
	}
}

void Museum::print_creations() const
{
	for (int i = 0; i < size_artists; i++)
	{
		creations_of_artists[i]->print();
	}
}

void Museum::print_images() const
{
	for (int i = 0; i < size_creations; i++)
		if (typeid(creations_of_artists[i]) == typeid(Image*))
			creations_of_artists[i]->print();
}

void Museum::print_statues() const
{
	for (int i = 0; i < size_creations; i++)
		if (typeid(creations_of_artists[i]) == typeid(Statue*))
			creations_of_artists[i]->print();
}

void Museum::print_creations_specific_artist() const
{
	char name_artist[30];
	cout << "Enter name of an artist to print the details about all its creations:" << endl;
	cin >> name_artist;
	for (int i = 0; i < size_artists; i++)
		if (strcmp(artists[i]->get_name(), name_artist) == 0)
			cout << *(artists[i]);

}

void Museum::print_creations_specific_current() const
{
	char current[30];
	cout << "Enter a certain current in art and the artists and the details of the artists with this kind of crrations will be printed:" << endl;
	cin >> current;
	for (int i = 0; i < size_creations; i++)
		if (strcmp(creations_of_artists[i]->get_current(), current) == 0)
			creations_of_artists[i]->print();
}

void Museum::print_artists_at_least_one_image() const
{
	for (int i = 0; i < size_artists; i++)
	{
		for (int j = 0; j < size_creations; j++)
		{
			if (strcmp(artists[i]->get_name(), creations_of_artists[j]->artist->get_name()) == 0)
			{
				if (typeid(creations_of_artists[j]) == typeid(Image*))
				{
					cout << (*artists[i]);
					break;
				}
			}
		}

	}

}

void Museum::print_artists_at_least_one_statue() const
{
	for (int i = 0; i < size_artists; i++)
	{
		for (int j = 0; j < size_creations; j++)
		{
			if (strcmp(artists[i]->get_name(), creations_of_artists[j]->artist->get_name()) == 0)
				if (typeid(creations_of_artists[j]) == typeid(Statue*))
				{
					cout << (*artists[i]);
					break;
				}
		}
	}
}

void Museum::print_statues_above_specific_weight() const
{
	float statue_weight;
	cout << "Enter a certain weight,and all the details about the statues above this weight will be printed:";
	cin >> statue_weight;
	for (int i = 0; i < size_creations; i++)
		if (dynamic_cast<Statue*>(creations_of_artists[i]))
			if ((dynamic_cast<Statue*>(creations_of_artists[i]))->get_weight() > statue_weight)
				creations_of_artists[i]->print();
}

void Museum::menu()
{
	int option, menu = 1;
	cout << "Welcome to the museum operation system!" << endl;
	cout << "Choose one of the following options(enter number between 1 to 13)" << endl;
	while (menu)
	{
		cout << "1.Add a new artist with no creations" << endl;
		cout << "2.Adding a creation" << endl;
		cout << "3.Remove a creation" << endl;
		cout << "4.Printing all the data of the artists with at least one creation" << endl;
		cout << "5.Printing the data about all the creations in the museum" << endl;
		cout << "6.Printing the data about all the images in the museum" << endl;
		cout << "7.Printing the data about all the statues in the museum" << endl;
		cout << "8.Printing the data about all the creations of a chosen artist" << endl;
		cout << "9.Printing the data about all the creations of a chosen current" << endl;
		cout << "10.Printing the data about all the artists who has at least one image" << endl;
		cout << "11.Printing the data about all the artists who has at least one statue" << endl;
		cout << "12.Printing the data about all the statues above a chosen weight" << endl;
		cout << "13.Exit from the operation system" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "You chose to add a new artist with no creations" << endl;
			add_artist();
			break;

		case 2:
			cout << "You chose to add a creation" << endl;
			add_creation();
			break;

		case 3:
			int index;
			cout << "You chose to remove a creation" << endl;
			cout << "Enter an index of creation you want to remove:" << endl;
			cin >> index;
			remove_creation(index);
			break;

		case 4:
			cout << "You chose to print all the data of the artists with at least one creation" << endl;
			print_artists_one_creation();
			break;

		case 5:
			cout << "You chose to print the data about all the creations in the museum" << endl;
			print_creations();
			break;

		case 6:
			cout << "You chose to print the data about all the images in the museum" << endl;
			print_images();
			break;
		case 7:
			cout << "You chose to print the data about all the statues in the museum " << endl;
			print_statues();
			break;

		case 8:
			cout << "You chose to print the data about all the creations of a chosen artist" << endl;
			print_creations_specific_artist();
			break;

		case 9:
			cout << "You chose to print the data about all the creations of a chosen current" << endl;
			print_creations_specific_current();
			break;

		case 10:
			cout << "You chose to print the data about all the artists who has at least one image" << endl;
			print_artists_at_least_one_image();
			break;

		case 11:
			cout << "You chose to print the data about all the artists who has at least one statue" << endl;
			print_artists_at_least_one_statue();
			break;
		case 12:
			cout << "You chose to print the data about all the statues above a chosen weight" << endl;
			print_statues_above_specific_weight();
			break;
		case 13:
			menu = 0;
			cout << "*************Goodbye!********************" << endl;
			Museum::~Museum();
		default:
			cout << "You entered a wrong option in the menu. Try again" << endl;
		}
	}
}

Museum::~Museum()
{
	for (int i = 0; i < size_creations; i++)
	{
		creations_of_artists[i]->~Creation();
		size_creations--;
	}
	for (int i = 0; i < size_artists; i++)
	{
		artists[i]->~Artist();
		size_artists--;
	}
}