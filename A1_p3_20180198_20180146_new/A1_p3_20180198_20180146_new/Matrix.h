#pragma once
#include<iostream>
using namespace std;
template <class T>
class Matrix
{
private:
	int row, column;
	T** matrix;
public:
	Matrix();
	 
	Matrix(int ro,int col);
	void setMatrix();
	void printMatrix();
	Matrix<T>operator-(Matrix ma);
	Matrix<T>operator+(Matrix ma);
	Matrix<T>operator*(Matrix ma);
	Matrix<T> transpose();
	friend istream& operator>>(istream& inp, Matrix<T>& ma) {
		cout << "enter the matrix " << ma.row << "*" << ma.column << endl;
		for (int i = 0; i < ma.row; i++)
		{
			for (int j = 0; j < ma.column; j++)
			{
				inp >> ma.matrix[i][j];
			}
		}
		return inp;
	}

	friend ostream& operator<<(ostream& out, Matrix<T>& ma) {
		for (int i = 0; i < ma.row; i++)
		{
			for (int j = 0; j < ma.column; j++)
			{
				out << ma.matrix[i][j] << " ";
			}
			cout << endl;
		}
		return out;
	}


	
};


