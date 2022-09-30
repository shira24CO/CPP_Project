#define _CRT_SECURE_NO_WARNINGS
#include "myArray.h"
#include <iostream>


using namespace std;

MyArray::MyArray()
{
	array = NULL;
	length = 0;
}

MyArray::MyArray(float* arr, int leng)
{
	if (leng == 0)
	{
		length = 0;
		arr = NULL;
		return;
	}
	array = new float[leng];
	if (arr == NULL)
	{
		length = 0;
	}
	else
	{
		length = leng;
		for (int i = 0; i < length; i++)
		{
			array[i] = arr[i];
		}
	}
}
MyArray::MyArray(int leng)
{
	if (leng == 0)
	{
		length = 0;
		array = NULL;
		return;
	}
	array = new float[leng];
	if (array == NULL)
	{
		length = 0;
	}
	else
	{
		length = leng;
		for (int i = 0; i < length; i++)
		{
			array[i] = 0.0;
		}
	}
}

MyArray::MyArray(const MyArray& a)
{
	if (a.length == 0)
	{
		length = 0;
		array = NULL;
		return;
	}

	array = new float[a.length];
	if (array == NULL)
	{
		length = 0;
	}
	else
	{
		length = a.length;
		for (int i = 0; i < a.length; i++)
		{
			array[i] = a.array[i];
		}
	}
}


bool MyArray::newArr(float* arr, int leng)
{
	if (array == NULL)
	{
		length = 0;
		return false;
	}
	if (arr == NULL || leng == 0)
	{
		return false;
	}
	else
	{
		delete[] array;
		length = leng;
		array = new float[length];
		if (array == NULL)
			return false;
		for (int i = 0; i < length; i++)
		{
			array[i] = arr[i];
		}
	}

	return true;
}

bool MyArray::changeNumber(float number, int index)
{
	if (index<0 || index>length - 1)
	{
		cout << "Bad index" << endl;
		return false;
	}

	else
	{
		array[index] = number;
		cout << "Changed" << endl;
		return true;
	}
}

float MyArray::sumArr()
{
	float sum = 0;
	for (int i = 0; i < length; i++)
		sum += array[i];
	return sum;
}

int MyArray::amountArr()
{
	if (array == NULL)
		return 0;
	return length;
}


void MyArray::print()
{
	if (array == NULL)
	{
		cout << "The array it's empty" << endl;
	}
	for (int i = 0; i < length; i++)
		cout << array[i] << " ";
}


bool MyArray::isLegalIndex(float& a, int index)
{
	if (index > 0 && index < length)
	{
		a = array[index];
		return true;
	}
	else
	{
		return false;
	}

}


