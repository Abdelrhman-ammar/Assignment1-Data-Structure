#pragma once
#include "Fraction.h"

class FractionCalculator
{
private:
	Fraction firstFraction;
	Fraction secoundFraction;
	Fraction result;

public:
	FractionCalculator();
	FractionCalculator(Fraction firstFraction, Fraction secoundFraction);
	void setTwoFraction(Fraction firstFraction, Fraction secoundFraction);
	void setTwoFractionInCommand();
	Fraction addition();
	Fraction division();
	Fraction multiplication();
	Fraction supstruction();
	Fraction getResult();
};

