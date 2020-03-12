#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;


int greatestCommonDivisors(int number1, int number2)
{
	if (number1 == 0 && number2 == 0)
	{
		return 1;
	}
	if (number1 == 0)
		return number2;
	return greatestCommonDivisors(number2 % number1, number1);
}


Fraction::Fraction() :denominator(1), numerator(1) {}


Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0 && numerator!=0)
	{
		cout << "Error: Denominator value cant be negative." << endl;
		denominator = 1;
	}
	int commonDicisor = greatestCommonDivisors(numerator, denominator);
	if (commonDicisor != 1)
	{
		numerator /= commonDicisor;
		denominator /= commonDicisor;
	}
	this->numerator = numerator;
	this->denominator = denominator;
}


Fraction Fraction::operator+(const Fraction object)
{
	int commonDivisor;
	Fraction result;
	result.numerator = numerator * object.denominator + denominator * object.numerator;
	result.denominator = denominator * object.denominator;
	commonDivisor = greatestCommonDivisors(result.numerator, result.denominator);
	if (commonDivisor != 1)
	{
		result.numerator /= commonDivisor;
		result.denominator /= commonDivisor;
	}
	return result;
}


Fraction Fraction::operator-(const Fraction object)
{
	int commonDivisor;
	Fraction result, fraction1 , fraction2 = object;
	fraction1.numerator = numerator;
	fraction1.denominator = denominator;
	//make to fraction has same denominator 
	fraction1.denominator *= fraction2.denominator;
	fraction1.numerator *= fraction2.denominator;
	fraction2.numerator *= denominator;
	fraction2.denominator *= denominator;
	//============================================
	result.numerator = fraction1.numerator - fraction2.numerator;
	result.denominator = fraction1.denominator;
	commonDivisor = greatestCommonDivisors(result.numerator, result.denominator);
	if (commonDivisor != 1)
	{
		result.numerator /= commonDivisor;
		result.denominator /= commonDivisor;
	}
	return result;
}


Fraction Fraction::operator*(const Fraction object)
{
	int commonDivisor;
	Fraction result;
	result.numerator = numerator * object.numerator;
	result.denominator = denominator * object.denominator;
	commonDivisor = greatestCommonDivisors(result.numerator, result.denominator);
	if (commonDivisor != 1)
	{
		result.numerator /= commonDivisor;
		result.denominator /= commonDivisor;
	}
	return result;
}


Fraction Fraction::operator/(const Fraction object)
{
	
	Fraction result, fraction2;
	if (object.numerator == 0 && object.denominator == 0)
	{
		cout << "Error cant Divide By Zero" << endl;
		return result;
	}
	fraction2.numerator = object.denominator;
	fraction2.denominator = object.numerator;
	result = *this * fraction2;
	return result;
}


bool Fraction::operator==(const Fraction object)
{
	return(numerator == object.numerator 
			&& denominator == object.denominator);
}


bool Fraction::operator<(const Fraction object)
{
	return((numerator / denominator) < (object.numerator / object.denominator));
}


bool Fraction::operator>(const Fraction object)
{
	return((numerator / denominator) > (object.numerator / object.denominator));
}


bool Fraction::operator<=(const Fraction object)
{
	return((numerator / denominator) <= (object.numerator / object.denominator));
}


bool Fraction::operator>=(const Fraction object)
{
	return((numerator / denominator) >= (object.numerator / object.denominator));
}

/*===================================================================================================================*/


istream& operator>>(istream& input, Fraction& object)
{
	string divid;
	cout << "Enter The Fraction:__";
	input >> object.numerator;
	input >> divid;
	input >> object.denominator;
	while ((object.denominator == 0 && object.numerator != 0 )|| divid != "/")
	{
		cout << "Error: Denominator value cant be negative and sign must be '/' ex 1/3." << endl;
		cout << "Enter The Fraction Again:__";
		input >> object.numerator;
		input >> divid;
		input >> object.denominator;
	}
	int commonDicisor = greatestCommonDivisors(object.numerator, object.denominator);
	if (commonDicisor != 1)
	{
		object.numerator /= commonDicisor;
		object.denominator /= commonDicisor;
	}
	return input;
}


ostream& operator<<(ostream& output, const Fraction& object)
{
	output << object.numerator << '/' << object.denominator;
	return output;
}



