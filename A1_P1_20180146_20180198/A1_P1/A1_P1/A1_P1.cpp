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


int main()
{
    BigDecimalInt number1, number2, result;
    //BigDecimalInt x(145), y("23");
    //cout << x + y << endl;
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
    return 0;
}
