#include <iostream>
#include <string>
#include "Fraction.h"
#include "FractionCalculator.h"
using namespace std;
int main()
{
    FractionCalculator object;
    object.setTwoFractionInCommand();
    cout << object.addition() << endl;
    cout << object.division() << endl;
    cout << object.multiplication() << endl;
    cout << object.supstruction() << endl;
    return 0;
}