#include "Matrix.h"
#include <iostream>
using namespace std;

template<class T>
Matrix<T> ::Matrix()
{
	cout << "enter no row: " << endl;
	cin >> row;
	cout << "enter no column: " << endl;
	cin >> column;
	matrix = new T * [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i]=new T[column];
	}
}

template<class t>
void Matrix<t>::setMatrix()
{
	cout << "enter the elements of matrix " << endl;
	for (int ro = 0; ro < row; ro++)
	{
		cout << "enter row no " << ro + 1 << endl;
		for (int col = 0; col < column; col++)
		{
			cin >> matrix[ro][col];
		}
	}
}

template<class t>
void Matrix<t>::printMatrix()
{
	for (int ro = 0; ro < row; ro++)
	{
		for (int col = 0; col < column; col++)
		{
			cout << matrix[ro][col] << " " << endl;
		}
		cout << endl;
	}
}
