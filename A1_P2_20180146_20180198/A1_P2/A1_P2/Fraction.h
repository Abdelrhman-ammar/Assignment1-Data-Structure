#pragma once
#include <iostream>
using namespace std;
class Fraction
{
private:
	int denominator;
	int numerator;
public:
	Fraction();
	Fraction(int numerator, int denominator);
	Fraction operator+(const Fraction object);
	Fraction operator-(const Fraction object);
	Fraction operator*(const Fraction object);
	Fraction operator/(const Fraction object);
	bool operator==(const Fraction object);
	bool operator<(const Fraction object);
	bool operator>(const Fraction object);
	bool operator>=(const Fraction object);
	bool operator<=(const Fraction object);
	friend int greatestCommonDivisors(int number1, int number2);
	friend istream& operator>>(istream& input, Fraction& object);
	friend ostream& operator<<(ostream& output, const Fraction& object);
};

