#pragma once
template <class T>
class Matrix
{
private:
	int row,column;
	T **matrix;
public:
	Matrix();
	void setMatrix();
	void printMatrix();
};


