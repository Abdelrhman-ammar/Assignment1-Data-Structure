#include "FractionCalculator.h"

FractionCalculator::FractionCalculator()
{
	cout << "Two Fraction = 1" << endl;
}


FractionCalculator::FractionCalculator(Fraction firstFraction, Fraction secoundFraction)
{
	this->firstFraction = firstFraction;
	this->secoundFraction = secoundFraction;
}

void FractionCalculator::setTwoFraction(Fraction firstFraction, Fraction secoundFraction)
{
	this->firstFraction = firstFraction;
	this->secoundFraction = secoundFraction;
}


void FractionCalculator::setTwoFractionInCommand()
{
	cin >> firstFraction >> secoundFraction;
}

Fraction FractionCalculator::addition()
{
	result = firstFraction + secoundFraction;
	return result;
}

Fraction FractionCalculator::division()
{
	result = firstFraction / secoundFraction;
	return result;
}

Fraction FractionCalculator::multiplication()
{
	result = firstFraction * secoundFraction;
	return result;
}

Fraction FractionCalculator::supstruction()
{
	result = firstFraction - secoundFraction;
	return result;
}

Fraction FractionCalculator::getResult()
{
	return result;
}
