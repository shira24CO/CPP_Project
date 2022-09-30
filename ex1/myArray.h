#define _CRT_SECURE_NO_WARNINGS
#define MYARRAY_H

class MyArray
{
private:
	float* array;
	int length;
public:
	MyArray();
	MyArray(float* arr, int leng);
	MyArray(int leng);
	MyArray(const MyArray& a);
	bool newArr(float* arr, int leng);
	bool changeNumber(float number, int index);
	float sumArr();
	int amountArr();
	void print();
	bool isLegalIndex(float& a, int index);
};