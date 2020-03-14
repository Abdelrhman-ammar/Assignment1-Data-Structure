#include <iostream>
#include <string>
#include "Fraction.h"
#include "FractionCalculator.h"
using namespace std;

void menue()
{
    cout << "1- Perform Fraction Addition" << endl;
    cout << "2- Perform Fraction Subtraction" << endl;
    cout << "3- Perform Fraction Multiplication" << endl;
    cout << "4- Perform Fraction Division" << endl;
    cout << "5- Exit" << endl;
}

int main()
{
    FractionCalculator object;
    /*object.setTwoFractionInCommand();
    cout << object.addition() << endl;
    cout << object.division() << endl;
    cout << object.multiplication() << endl;
    cout << object.supstruction() << endl;
    */
    string str;
    Fraction fraction;
    cout << "Welcome to FCI Fraction Calculator" << endl;
    cout << "---------------------------------------------------" << endl;
    menue();
    cin >> str;
    object.setTwoFractionInCommand();
    if (str == "1")
    {
        object.addition();
    }
    else if (str == "2")
    {
        object.supstruction();
    }
    else if (str == "3")
    {
        object.multiplication();
    }
    else if (str == "4")
    {
        object.division();
    }
    else if (str == "5")
    {
        return 0;
    }
    else
    {
        cout << "Error Invalid input.........." << endl << endl;
    }
    cout << object.getResult() << endl;
    while (true)
    {
        menue();
        cin >> str;
        if (str == "1")
        {
            cout << "Enter The Fraction: ";
            cin >> fraction;
            object.addition(fraction);
        }
        else if (str == "2")
        {
            cout << "Enter The Fraction: ";
            cin >> fraction;
            object.supstruction(fraction);
        }
        else if (str == "3")
        {
            cout << "Enter The Fraction: ";
            cin >> fraction;
            object.multiplication(fraction);
        }
        else if (str == "4")
        {
            cout << "Enter The Fraction: ";
            cin >> fraction;
            object.division(fraction);
        }
        else if (str == "5")
        {
            return 0;
        }
        else
        {
            cout << "Error Invalid input.........." << endl << endl;
        }
        cout << object.getResult() << endl;
    }
    return 0;
}