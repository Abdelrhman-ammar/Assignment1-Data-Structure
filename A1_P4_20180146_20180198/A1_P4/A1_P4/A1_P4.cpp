#include <iostream>
using namespace std;
//recurtion function return 1 if the power is 0
int power(int a, int n)
{
    if (n != 0)
    {
        return a * power(a, n - 1);
    }
    else
    {
        return 1;
    }
}
//recurtion function return 1 if the power is 0
//it work easially if the num is even
int power_2(int a, int n)
{
    if (n%2== 0)
    {
        return power(a,n/2) * power(a,n/2);
    }
    else if (n!=0)
    {
        return a * power(a, n - 1);
    }
    else
    {
        return 1;
    }

}
int main()
{
    cout << "2^5=" << power(2, 5) << endl;
    cout << "2^5=" << power_2(2, 5) << endl;

    cout << "2^4=" << power(2,4) << endl;
    cout << "2^4=" << power_2(2,4) << endl;

}
 