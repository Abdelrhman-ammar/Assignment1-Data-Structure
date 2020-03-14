#include "FractionCalculator.h"

//default constructor set to fraction = 1
FractionCalculator::FractionCalculator()
{
	//cout << "Two Fraction = 1" << endl;
}

//paramitarize constructor take tow fraction
FractionCalculator::FractionCalculator(Fraction firstFraction, Fraction secoundFraction)
{
	this->firstFraction = firstFraction;
	this->secoundFraction = secoundFraction;
}

//store tow fraction in the object
void FractionCalculator::setTwoFraction(Fraction firstFraction, Fraction secoundFraction)
{
	this->firstFraction = firstFraction;
	this->secoundFraction = secoundFraction;
}

//take the fractions from user
void FractionCalculator::setTwoFractionInCommand()
{
	cout << "Enter First Fraction:__" << endl;
	cin >> firstFraction;
	cout << "Enter Secound Fraction:__" << endl;
	cin >> secoundFraction;
}

//adding two fraction that is already store in the object
Fraction FractionCalculator::addition()
{
	result = firstFraction + secoundFraction;
	return result;
}

//divide two fraction that is already store in the object
Fraction FractionCalculator::division()
{
	result = firstFraction / secoundFraction;
	return result;
}

//multibli two fraction that is already store in the object
Fraction FractionCalculator::multiplication()
{
	result = firstFraction * secoundFraction;
	return result;
}

//substract two fraction that is already store in the object
Fraction FractionCalculator::supstruction()
{
	result = firstFraction - secoundFraction;
	return result;
}

//adding fraction with the result of last process that already store in the object
Fraction FractionCalculator::addition(Fraction object)
{
	result = result + object;
	return result;
}

//divide fraction with the result of last process that already store in the object
Fraction FractionCalculator::division(Fraction object)
{
	result = result / object;
	return result;
}

//multibli fraction with the result of last process that already store in the object
Fraction FractionCalculator::multiplication(Fraction object)
{
	result = result * object;
	return result;
}

//substract fraction with the result of last process that already store in the object
Fraction FractionCalculator::supstruction(Fraction object)
{
	result = result - object;
	return result;
}

Fraction FractionCalculator::getResult()
{
	return result;
}
