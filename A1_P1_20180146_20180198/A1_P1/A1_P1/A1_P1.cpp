#include <iostream>
#include <string>
#include <typeinfo>
#include "BigDecimalInt.h"
using namespace std;

BigDecimalInt add(BigDecimalInt num1, BigDecimalInt num2)
{
    BigDecimalInt result = num1 + num2;
    cout << "sum of " << num1 << " and " << num2 << " = " << result << endl;
    return result;
}

void menue()
{
    cout << "1- Perform Addition" << endl;
    cout << "2- Perform Subtraction" << endl;
    cout << "3- Exit" << endl;
}

int main()
{
    cout << "Welcome to FCI Calculator" << endl;
    cout << "---------------------------------------------------" << endl;
    
    BigDecimalInt number1, number2, result;
    /*BigDecimalInt x(145), y("-23");
    cout << x + y << endl;
    string exit;
    while (true)
    {
        cout << "Enter 'Q' if you want to Exist else Enter any thing." << endl;
        cin >> exit;
        if (exit == "Q")
        {
            return 0;
        }
        cin.ignore();
        number1.sitnumber();
        number2.sitnumber();
        add(number1, number2);
    }
    */
    string str;
    while (true)
    {
        menue();
        cin >> str;
        if (str == "1")
        {
            cin.ignore();
            number1.sitnumber();
            cout << "Number1 = " << number1 << endl;
            number2.sitnumber();
            cout << "Number2 = " << number2 << endl;
            cout << "number1 + number2 = " << number1 + number2 << endl;
        }
        else if (str == "2")
        {
            cin.ignore();
            number1.sitnumber();
            cout << "Number1 = " << number1 << endl;
            number2.sitnumber();
            cout << "Number2 = " << number2 << endl;
            cout << "number1 - number2 = " << number1 - number2 << endl;
        } 
        else if (str == "3")
        {
            return 0;
        }
        else
        {
            cout << "Error Invalid Input." << endl;
        }
        cout << endl << endl;
    }
    
    return 0;
}
