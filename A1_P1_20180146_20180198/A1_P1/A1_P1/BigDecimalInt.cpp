#include "BigDecimalInt.h"
#include <sstream>
#include<iostream> 
#include<algorithm>
using namespace std;


bool isNumber(string inputString)
{
	for (int counter = 0; counter < inputString.length(); counter++)
	{
		if (isdigit(inputString[counter]) == false )
		{
			if (counter == 0 && inputString[counter] == '-')
			{
				continue;
			}
			return false;
		}
	}
	return true;
}


char addTwoDigit(char ch1, char ch2, int& reminder)
{
	int sum = 0;
	sum = ch1 - '0' + ch2 - '0' + reminder;
	if (sum <= 9)
	{
		reminder = 0;
		return char(sum + '0');
	}
	else
	{
		reminder = 1;
		return char(sum - 10 + '0');
	}
}

BigDecimalInt::BigDecimalInt() : number("00000000000000000000000000000000") {}

BigDecimalInt::BigDecimalInt(string number)
{
	this->number = number;
	if (isNumber(number))
	{
		this->number = number;
	}
	else
	{
		cout << "Error number must be interger and not character." << endl;
		this->number = "00000000000000000000000000000000";
	}
}
void BigDecimalInt::sitnumber()
{
	cout << "Enter the number:__" << endl;
	getline(cin, number);
	while (!isNumber(number))
	{
		cout << "Error number must be interger and not character." << endl;
		cout << "Enter the number:__" << endl;
		getline(cin, number);
	}
}


BigDecimalInt BigDecimalInt::operator+(BigDecimalInt const object)
{
	int countNumber1 = number.length()-1;
	int countNumber2 = object.number.length()-1;
	int reminder = 0;
	bool negative = false;
	int counter = max(number.length(), object.number.length()) - 1, max = 0;
	BigDecimalInt result;
	string sum;
	char ch1, ch2;
	result.number = "";
	if (number[0] == '-' && object.number[0] == '-' ||
		number[0] != '-' && object.number[0] != '-')
	{
		if (number[0] == '-' && object.number[0] == '-')
		{
			max = 1;
			counter--;
			result.number = "-";
		}
		while (counter > -1)
		{
			if(countNumber1>=max)
				ch1 = number[countNumber1--];
			else
				ch1 = '0';
			if(countNumber2>=max)
				ch2 = object.number[countNumber2--];
			else
				ch2 = '0';
			sum += addTwoDigit(ch1, ch2, reminder);
			cout << "ch1=" << ch1 << "	" << "ch2" << ch2 << endl;
			counter--;
		}
		if (reminder == 1)
		{
			sum += '1';
		}
		counter = sum.length();
		while (counter > -1)
		{
			result.number += sum[counter];
			counter--;
		}
	}
	return result;
}


istream& operator>>(istream& input, BigDecimalInt& object)
{
	cout << "Enter the number:__" << endl;
	getline(input, object.number);
	while (!isNumber(object.number))
	{
		cout << "Error number must be interger and not character." << endl;
		cout << "Enter the number:__" << endl;
		getline(input, object.number);
	}
	return input;
}
ostream& operator<<(ostream& output, const BigDecimalInt& object)
{
	output << object.number;
	return output;
}