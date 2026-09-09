// cau1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// tìm số lớn nhất trong 3 chữ số a,b,c


int main()
{
    int a, b, c;
    cout << "Nhap 3 so a, b, c: ";
    cin >> a >> b >> c;

    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;

    cout << "So lon nhat la: " << max << endl;

    return 0;
}


