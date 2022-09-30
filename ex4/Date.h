//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Date
{
private:
	int day, month, year;
	bool set_day(int d);
	bool set_month(int month);
	bool set_year(int y);

public:
	int get_day();
	int get_month();
	int get_year();
	void today();
	friend istream& operator>>(istream& is, Date& d);
	Date& operator=(const Date &d);
	Date();
	Date(int d, int m, int y);
	void printDate() const;
	void print_month_name();
	int num_days_in_month();
	bool check_year();
	~Date();
	void next_day();
	void print_date_values();
	bool valid_date(int d, int m, int y);
	bool set_date(int d, int m, int y);
};