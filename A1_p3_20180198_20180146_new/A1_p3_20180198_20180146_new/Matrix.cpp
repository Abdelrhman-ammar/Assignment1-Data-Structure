#include "Matrix.h"
#include <iostream>
using namespace std;
template<class T>
Matrix<T> ::Matrix()
{
	 
} 
//constructor to initialize an dynamic 2d array with column and rows
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
 
/* operator for substraction two matrix
   
*/
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
/* operator for adding two matrix

*/
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
/* 
 operator for multiblying two matrix
*/
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
/* 
   operator for transpose the matrix
*/
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

