// cau2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// tính n!

int main()
{ 
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int giaiThua = 1;
    for (int i = 1; i <= n; i++)
    {
        giaiThua *= i;
    }
    cout << n << "! = " << giaiThua << endl;
    return 0;
}



