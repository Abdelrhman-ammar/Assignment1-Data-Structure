#include <iostream>
#include <string>
using namespace std;
class BigDecimalInt
{
private:
	string number;
public:
	BigDecimalInt();
	BigDecimalInt(string number);
	BigDecimalInt(int number);
	void sitnumber();
	char addTwoDigit(char ch1, char ch2, int& reminder);
	BigDecimalInt operator+(BigDecimalInt const object);
	BigDecimalInt operator-(BigDecimalInt const object);
	friend bool isNumber(string inputString);
	friend string reverse(string word);
	friend bool isbigger(string number1, string number2);
	friend istream& operator>>(istream& input, BigDecimalInt& object);
	friend ostream& operator<<(ostream& output, const BigDecimalInt& object);
};