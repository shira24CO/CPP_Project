//Ilan Shklover,ID:206753550 ,Shira Cohen ,ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "date.h"
#include<time.h>

bool Date::set_day(int d)
{
	if (d<1 || d>num_days_in_month())
		return false;
	day = d;
	return true;
}

bool Date::set_month(int m)
{
	if (m < 0 || m>12)
		return false;
	month = m;
	return true;
}

bool Date::set_year(int y)
{
	if (y > 0)
		year = y;
	return false;
}

int Date::get_day()
{
	return this->day;
}

int Date::get_month()
{
	return this->month;
}

int Date::get_year()
{
	return this->year;
}
void Date::today()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	this->day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}
Date::Date()
{
	this->today();
		
}

Date::Date(int d, int m, int y)
{
	if (!valid_date(d, m, y))
		today();
	else {
		set_month(m);
		set_year(y);
		set_day(d);
	}
}

void Date::printDate() const
{
	if (day < 10)
		cout << "0" << day << "/" << month << "/" << year << endl;
	if ((month) < 10)
		cout << day << "/" << "0" <<month << "/" << year << endl;
	else
		cout <<day << "/" << month <<"/"<<year << endl;
}

void Date::print_month_name()
{
	switch (month)
	{
	case 1:
		cout << "January" << endl;
		break;
	case 2:
		cout << "February" << endl;
		break;
	case 3:
		cout << "March" << endl;
		break;
	case 4:
		cout << "April" << endl;
		break;
	case 5:
		cout << "May" << endl;
		break;
	case 6:
		cout << "June" << endl;
		break;
	case 7:
		cout << "July" << endl;
		break;
	case 8:
		cout << "August" << endl;
		break;
	case 9:
		cout << "September" << endl;
		break;
	case 10:
		cout << "September" << endl;
		break;
	case 11:
		cout << "October" << endl;
		break;
	case 12:
			cout << "December" << endl;
			break;
	default:
		cout << "Wrong month Input" << endl;
	}
}

bool Date::check_year()
{
	if (year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0))
		return true;
	return false;
}

int Date::num_days_in_month()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (check_year() == true)
		return 29;
	else if (check_year() == false)
		return 28;
	else
		return 30;
	
}

void Date::print_date_values()
{
	cout << "Number of day in the month: " << day-1 << endl;
	cout << "Month: " << month << endl;
	cout << "Year: " << year << endl;
}

Date::~Date()
{
	cout << "Destruction Date" << endl;
	print_date_values();
}

void Date::next_day()
{
	if (day < num_days_in_month())
		day++;
	if (day == num_days_in_month() && month != 12)//end of the month(not December)
	{
		day = 1;
		month++;
	}
	if (day == num_days_in_month() && month == 12)//end of the year
	{
		day = 1;
		month = 1;
		year++;
	}

}

bool Date::valid_date(int d, int m, int y)
{
	if (d<1 || d>num_days_in_month())
		return false;
	if (m < 1 || m>12)
		return false;
	if (y < 0)
		return false;
	return true;
}

bool Date:: set_date(int d, int m, int y)
{
	if (!valid_date(d, m, y))
		return false;
	
	set_month(m);
	set_year(y);
	set_day(d);
	return true;
	
	
}

istream& operator>>(istream& is, Date& d)
{
	is >> d.day >> d.month >> d.year;
	return is;
}

Date& Date::operator=(const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
	return *this;
}