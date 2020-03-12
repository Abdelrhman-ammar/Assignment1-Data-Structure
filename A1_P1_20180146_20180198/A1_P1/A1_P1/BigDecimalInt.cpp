#include "BigDecimalInt.h"
#include <sstream>
#include<iostream> 
#include<algorithm>
using namespace std;

string trimNegative(string word)
{
	if (word[0] != '-')
	{
		return word;
	}
	else
	{
		string result = "";
		for (int counter = 1; counter < word.length(); counter++)
		{
			result += word[counter];
		}
		return result;
	}
}

int getDigites(int number)
{
	if (number == 0)
		return number;
	getDigites(number / 10);
}

bool isbigger(string number1, string number2)
{
	int sizeNumber1 = number1.length();
	int sizeNumber2 = number2.length();
	if (sizeNumber1 > sizeNumber2)
	{
		return true;
	}
	else if (sizeNumber1 < sizeNumber2)
	{
		return false;
	}
	else
	{
		for (int counter = 0; counter < sizeNumber1; counter++)
		{
			if (number1[counter] > number2[counter])
			{
				return true;
			}
			else if (number1[counter] < number2[counter])
			{
				return false;
			}
		}
	}
	return false;
}

string reverse(string word)
{
	string reversedWord = "";
	for (int counter = word.length() - 1; counter >= 0; counter--)
	{
		reversedWord += word[counter];
	}
	return reversedWord;
}


bool isNumber(string inputString)
{
	for (int counter = 0; counter < inputString.length(); counter++)
	{
		if (isdigit(inputString[counter]) == false)
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

BigDecimalInt::BigDecimalInt(int number)
{
	string word;
	word = "";
	if (number == 0)
	{
		this->number = "0";
	}
	else
	{
		bool negative = false;
		if (number < 0)
		{
			number *= -1;
			negative = true;
		}
		while (number != 0)
		{
			word += number % 10 + '0';
			number /= 10;
		}
		if (negative == true)
		{
			word += "-";
		}
		this->number = reverse(word);
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

char BigDecimalInt::addTwoDigit(char ch1, char ch2, int& reminder)
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

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt const object)
{
	BigDecimalInt resultObject;
	bool negative = false;
	string number1Trim = trimNegative(number);
	string number2Trim = trimNegative(object.number);
	string number1 = reverse(number1Trim);
	string number2 = reverse(number2Trim);
	if (!isbigger(number1Trim, number2Trim))
	{
		string temp = number1;
		number1 = number2;
		number2 = temp;
		negative = true;
	}
	string result = "";
	int carry = 0, substractDigit = 0;
	int sizeNumber1 = number1.length();
	int sizeNumber2 = number2.length();
	for (int counter = 0; counter < sizeNumber2; counter++)
	{
		substractDigit = ((number1[counter] - '0') - (number2[counter] - '0') - carry);
		if (substractDigit < 0)
		{
			substractDigit += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result += substractDigit + '0';
	}
	for (int counter = sizeNumber2; counter < sizeNumber1; counter++)
	{
		substractDigit = ((number1[counter] - '0') - carry);
		if (substractDigit < 0)
		{
			substractDigit += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result += substractDigit + '0';
	}
	if (negative == true)
	{
		result += '-';
	}
	resultObject.number = reverse(result);
	return resultObject;
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt const object)
{
	int countNumber1 = number.length() - 1;
	int countNumber2 = object.number.length() - 1;
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
			if (countNumber1 >= max)
				ch1 = number[countNumber1--];
			else
				ch1 = '0';
			if (countNumber2 >= max)
				ch2 = object.number[countNumber2--];
			else
				ch2 = '0';
			sum += addTwoDigit(ch1, ch2, reminder);
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
	else
	{
		result = *this - object;
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