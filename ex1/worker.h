#define _CRT_SECURE_NO_WARNINGS
#define WORKER_H



class Worker
{
private:
	char name [15]; //�� �����
	long ID;//���� ����� �����
	double salaryPerHour;//��� ����
	int numberOfRegularHours;//���� ����� ������� ������ ���
	int numberOfExtraHours;//���� ����� �������

	

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
