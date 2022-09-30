#define _CRT_SECURE_NO_WARNINGS
#define WORKER_H



class Worker
{
private:
	char name [15]; //שם העובד
	long ID;//מספר תעודת הזהות
	double salaryPerHour;//שכר לשעה
	int numberOfRegularHours;//מספר השעות הרגילות שהעובד עבד
	int numberOfExtraHours;//מספר השעות הנוספות

	

public:
	Worker();
	char* getName() { return name; }
	long getID() { return ID;}
	double getSalaryPerHour() { return salaryPerHour; }
	int getNumberOfRegularHours() { return numberOfRegularHours; }
	int getNumberOfExtraHours() {return numberOfExtraHours; }
	void setName(char* name);
	void setID(long ID);
	void setSalaryPerHour(double);
	void setNumberOfRegularHours(int);
	void setNumberOfExtraHours(int);
	double carculate();
	void point();


};
