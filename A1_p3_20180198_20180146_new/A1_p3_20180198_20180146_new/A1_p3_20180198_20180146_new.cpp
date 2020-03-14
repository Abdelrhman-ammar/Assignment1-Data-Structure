#include <iostream>
#include "Matrix.h"
#include "MAtrix.cpp"
using namespace std;
class MatrixCalculator {
public:
    //function to show menue for user
    void show_menue()
    {
        cout << "welcome to our MatrixCalculator" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1- Perform Matrix Addition" << endl;
        cout << "2- Perform Matrix Subtraction" << endl;
        cout << "3- Perform Matrix Multiplication" << endl;
        cout << "4- Matrix Transpose" << endl;
        cout << "5- Exit" << endl;
        cout << "enter your choise: ";


    }
    //constructor make all operations
    MatrixCalculator()
    {
        string choise_from_user;
        int col, ro;
        while (true)
        {
            show_menue();
            cin >> choise_from_user;
            //to check validation of input
            while (choise_from_user != "1" && choise_from_user != "2"&&choise_from_user != "3"&&choise_from_user != "4" && choise_from_user != "5")
            {
                cout << "enter right val" << endl;
                cin >> choise_from_user;
            }
            //if user enter "1" create two object of Matrix and do addition to them
            if(choise_from_user=="1")
            {
                cout << "enter row frist and col second for the two matrix" << endl;
                cin >> ro >> col;
                while (ro < 1 || col < 1)
                {
                    cout << "enter right value" << endl;
                    cout << "enter row frist and col second for the two matrix" << endl;
                    cin >> ro >> col;
                }
                Matrix<int> m1(ro,col), m2(ro, col),m3(ro,col);
                cin >> m1;
                cin >> m2;
                m3 = m1 + m2;
                cout << "the sum is" << endl;
                cout << m3 ;
                


            }
            //if user enter "2" create two object of class Matrix and do substraction to them
            else if(choise_from_user == "2")
            { 
                cout << "enter row frist and col second for the two matrix" << endl;
                cin >> ro >> col;
                while (ro < 1 || col < 1)
                {
                    cout << "enter right value" << endl;
                    cout << "enter row frist and col second for the two matrix" << endl;
                    cin >> ro >> col;
                }
                Matrix<int> m1(ro, col), m2(ro, col), m3(ro, col);
                cin >> m1;
                cin >> m2;
                m3 = m1 - m2;
                cout << "the result is" << endl;
                cout << m3;
            }
            //if user enter "3" create two object of class Matrix and do multiblying to them
            else if (choise_from_user == "3")
            {
                int ro2, col2;
                cout << "enter row frist and col second for the frist_MAtrix:" << endl;
                cin >> ro >> col;
                while (ro < 1 || col < 1)
                {
                    cout << "enter right value" << endl;
                    cout << "enter row frist and col second for the frist_MAtrix:" << endl;
                    cin >> ro >> col;
                }
                cout << "enter row frist and col second for the second_MAtrix:" << endl;
                cin >> ro2 >> col2;
                while (ro < 1 || col < 1|| col != ro2 ) 
                {
                    cout << "enter right value" << endl;
                   
                    cin >> ro2 >> col2;
                }

                Matrix<int> m1(ro, col), m2(ro2, col2), m3(ro, col2);
                cin >> m1;
                cin >> m2;
                cout << "the result is" << endl;
                m3 = m1 * m2;
                cout << m3;
            }
            //if user enter "4" create one object of class Matrix and do transpose
            else if (choise_from_user == "4")
            { 
                cout << "enter row frist and col second for the   matrix" << endl;
                cin >> ro >> col;
                while (ro < 1 || col < 1)
                {
                    cout << "enter right value" << endl;
                    cout << "enter row frist and col second for the   matrix" << endl;
                    cin >> ro >> col;
                }
                Matrix<int> m1(ro, col), m2(ro, col) ;
                cin >> m1;
              
                m2= m1.transpose();
                cout << "the result is" << endl;
                cout << m2;
            }
            //if user enter "5" close the program 
            else if (choise_from_user == "5")
            {
                break;
            }

        }
    }
    
};
int main()
{
    MatrixCalculator ma;

}
