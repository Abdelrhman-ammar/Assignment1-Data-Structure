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
	BigDecimalInt operator+(BigDecimalInt const object);
	friend bool isNumber(string inputString);
	friend char addTwoDigit(char ch1, char ch2, int& reminder);
	friend istream& operator>>(istream& input, BigDecimalInt& object);
	friend ostream& operator<<(ostream& output, const BigDecimalInt& object);
};