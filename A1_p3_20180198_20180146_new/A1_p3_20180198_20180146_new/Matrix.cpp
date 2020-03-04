#include "Matrix.h"
#include <iostream>
using namespace std;
template<class T>
Matrix<T> ::Matrix()
{
	 
}

 

template<class T>
Matrix<T>::Matrix(int ro, int col)
{
	row = ro;
	column = col;
	 
	matrix = new T * [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new T[column];
	}
}

template<class t>
void Matrix<t>::setMatrix()
{
	cout << "enter the elements of matrix " << endl;
	for (int ro = 0; ro < row; ro++)
	{
		 
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
			cout << matrix[ro][col] << " " ;
		}
		cout << endl;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix ma)
{
	Matrix<T> result(row, column);
	for (int ro = 0; ro < row; ro++)
	{
		for (int col = 0; col < column; col++)
		{
			result.matrix[ro][col] = matrix[ro][col] - ma.matrix[ro][col];
		}
	}
	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix ma)
{
	Matrix<T> result(row,column);
	for (int ro = 0; ro < row; ro++)
	{
		for (int col = 0; col < column; col++)
		{
			result.matrix[ro][col]= matrix[ro][col] + ma.matrix[ro][col];
		}
	}
	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix ma)
{
	Matrix result(row, ma.column);
	T* arr = new T[column];
	 
	for (int i = 0; i < row;i++)
	{
		for (int L = 0; L < ma.column; L++)
		{
			T sum = 0;
			for (int j = 0; j < column; j++)
			{
				arr[j] = matrix[i][j];
				
			}
			for (int j = 0; j < column; j++)
			{
				 sum+= (arr[j] * ma.matrix[j][L]);
				 
			}
			result.matrix[i][L] = sum;
		}
	}
	return result;

}

template<class T>
Matrix<T> Matrix<T>::transpose()
{
	Matrix result(row, column);
	for (int ro = 0; ro < row; ro++)
	{
		for (int col = 0; col < column; col++)
		{
			result.matrix[ro][col] = matrix[col][ro];
		}
	}
	return result;
}

