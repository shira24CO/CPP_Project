#define _CRT_SECURE_NO_WARNINGS
#include "myArray.h"
#include <iostream>

using namespace std;
int main()
{

    cout << "In this program there are 4 arrays created by different constructors: empty_arr, zero_arr, parameters_arr, copied_arr." << endl;
    int lengthZero, lengthParameters;
    cout << "Enter length of zero_arr:";
    cin >> lengthZero;
    cout << "Enter length of parameters_arr:";
    cin >> lengthParameters;
    float* arrP = new float[lengthParameters];
    cout << "Enter elements of parameters_arr:" << endl;
    for (int i = 0; i < lengthParameters; i++)
    {
        cin >> arrP[i];
    }
    MyArray parameters_arr(arrP, lengthParameters);
    MyArray empty_arr;
    cout << "empty_arr:";
    empty_arr.print();
    MyArray zero_arr(lengthZero);
    cout << "zero_arr: ";
    zero_arr.print();
    cout << endl;
    cout << "parameters_arr: ";
    parameters_arr.print();
    MyArray copied_arr(zero_arr);
    cout << endl << "Enter new length of zero_arr:" << endl;
    cin >> lengthZero;
    cout << "Enter elements of zero_arr:" << endl;
    float* arrZ = new float[lengthZero];
    for (int i = 0; i < lengthZero; i++)
    {
        cin >> arrZ[i];
    }

    zero_arr.newArr(arrZ, lengthZero);
    cout << "changing an element in zero_arr:" << endl;
    cout << "Enter index:";
    int index;
    float element;
    cin >> index;
    cout << "Enter element:";
    cin >> element;
    zero_arr.changeNumber(element, index);
    cout << endl << "changing an element in parameters_arr:" << endl;
    cout << "Enter index: ";
    cin >> index;
    cout << "Enter element:" << endl;
    cin >> element;
    parameters_arr.changeNumber(element, index);
    cout << endl << "changing an element in copied_arr:" << endl;
    cout << "Enter index:";
    cin >> index;
    cout << "Enter element:";
    cin >> element;
    copied_arr.changeNumber(element, index);

    cout << "zero_arr: ";
    zero_arr.print();
    cout << endl;
    cout << "parameters_arr: ";
    parameters_arr.print();
    cout << endl;
    cout << "copied_arr: ";
    copied_arr.print();
    cout << endl;
    cout << "Enter index: ";
    cin >> index;
    float a;


    if (empty_arr.isLegalIndex(a, index) == true)
    {
        cout << "empty_arr [" << index << "] = " << a << endl;
    }
    else
    {
        cout << "empty_arr [" << index << "] = Bad index." << endl;
    }

    if (zero_arr.isLegalIndex(a, index) == true)
    {
        cout << "zero_arr [" << index << "] = " << a << endl;
    }
    else
    {
        cout << "zero_arr [" << index << "] = Bad index." << endl;
    }

    if (parameters_arr.isLegalIndex(a, index) == true)
    {
        cout << "parameters_arr [" << index << "] = " << a << endl;
    }
    else
    {
        cout << "parameters_arr [" << index << "] = Bad index." << endl;
    }

    if (copied_arr.isLegalIndex(a, index) == true)
    {
        cout << "copied_arr [" << index << "] = " << a << endl;
    }
    else
    {
        cout << "copied_arr [" << index << "] = Bad index." << endl;
    }


    cout << "empty_arr: sum = " << empty_arr.sumArr();
    cout << ", " << "lengh = " << empty_arr.amountArr();
    cout << endl;

    cout << "zero_arr: sum = " << zero_arr.sumArr();
    cout << ", " << "lengh = " << zero_arr.amountArr();
    cout << endl;

    cout << "parameters_arr: sum = " << parameters_arr.sumArr();
    cout << ", " << "lengh = " << parameters_arr.amountArr();
    cout << endl;

    cout << "copied_arr: sum = " << copied_arr.sumArr();
    cout << ", " << "lengh = " << copied_arr.amountArr();
    cout << endl;


    return  0;

}
