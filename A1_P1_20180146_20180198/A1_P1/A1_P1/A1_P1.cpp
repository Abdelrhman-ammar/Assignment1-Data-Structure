#include <iostream>
#include <string>
#include <typeinfo>
#include "BigDecimalInt.h"
using namespace std;

int main()
{
    BigDecimalInt x("-18"), y("-1110"), z;
    //cin >> x;
    z = x + y;
    cout << z << endl;
    //cout << ('2'-'0')+('1'-'0') << endl;*/
    /*string s = "ahme";
    s += 'd';
    cout << s << endl;*/
    /*int reminder = 0;
    cout << addTwoDigit('9', '9', reminder);
    cout << reminder << endl;**/
    return 0;
}
